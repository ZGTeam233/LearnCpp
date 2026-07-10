Lambda 表达式是 C++11 引入的最具革命性的特性之一，它让 C++ 拥有了真正的“闭包”能力。从 C++11 到 C++20，Lambda 经历了多次重大进化，变得越来越强大、安全和灵活。

下面我将按版本为你梳理 C++11 到 C++20 中 Lambda 表达式的核心演进。

---

### 1. C++11：Lambda 的诞生
C++11 引入了 Lambda 的基本语法，解决了“如何方便地定义匿名函数和回调”的问题。

**基本语法：**
```cpp
[capture](parameters) -> return_type { body }
```

**核心特性：**
*   **捕获列表 (Capture List)**：决定了 Lambda 可以访问外部作用域的哪些变量。
    *   `[]`：不捕获任何变量。
    *   `[=]`：按**值**捕获外部所有变量（只读）。
    *   `[&]`：按**引用**捕获外部所有变量。
    *   `[this]`：捕获当前对象的 `this` 指针。
    *   可以混合使用，如 `[=, &x]`（默认按值，`x` 按引用）。
*   **返回类型推导**：如果函数体只有一个 `return` 语句，编译器会自动推导返回类型；否则需要使用 `->` 显式指定。

**代码示例：**
```cpp
int x = 10;
auto add_x = [x](int a) { return a + x; };      // 按值捕获 x
auto inc_x = [&x](int a) { x++; return a + x; }; // 按引用捕获 x

std::cout << add_x(5);  // 输出 15
std::cout << inc_x(5);  // 输出 16，且外部 x 变成 11
```

---

### 2. C++14：泛型与移动语义
C++14 让 Lambda 变得更加通用，并解决了 C++11 中无法捕获“仅移动类型”的痛点。

**核心特性：**
*   **泛型 Lambda (Generic Lambdas)**：参数可以使用 `auto`，相当于编译器自动生成一个模板函数。
*   **初始化捕获 (Init Capture / 广义捕获)**：允许在捕获列表中初始化变量，**完美支持移动语义**。

**代码示例：**
```cpp
// 1. 泛型 Lambda (相当于模板函数)
auto generic_add = [](auto a, auto b) { return a + b; };
std::cout << generic_add(1, 2);       // int
std::cout << generic_add(1.5, 2.5);   // double
std::cout << generic_add(std::string("a"), std::string("b")); // string

// 2. 初始化捕获 (移动捕获)
auto ptr = std::make_unique<int>(42);
// C++11 无法捕获 unique_ptr，C++14 可以通过 std::move 将其移入 Lambda
auto lambda = [p = std::move(ptr)]() { return *p; }; 
// 此时外部的 ptr 已经为空，所有权转移给了 lambda
```

---

### 3. C++17：编译期计算与安全的对象捕获
C++17 主要解决了 Lambda 在编译期求值以及对象生命周期安全的问题。

**核心特性：**
*   **`constexpr` Lambda**：只要满足条件，Lambda 默认就是 `constexpr` 的，可以在编译期求值。
*   **`*this` 捕获**：按值捕获**整个对象**，而不是 `this` 指针。解决了按值捕获成员变量时可能导致的悬垂指针问题。

**代码示例：**
```cpp
// 1. constexpr Lambda
constexpr auto square = [](int x) { return x * x; };
static_assert(square(5) == 25); // 编译期断言

// 2. *this 捕获 (解决生命周期问题)
struct Widget {
    int val = 10;
    auto get_func() {
        // C++11/14 中如果写 [=]，捕获的是 this 指针。
        // 如果 Widget 对象被销毁，lambda 调用时会引发未定义行为。
        // C++17 使用 [*this] 会拷贝整个 Widget 对象，保证安全。
        return [*this]() { return val; }; 
    }
};
```

---

### 4. C++20：模板化与现代化语法
C++20 对 Lambda 进行了大幅增强，使其在类型推导、构造和安全性上达到了新的高度。

**核心特性：**
*   **模板 Lambda (Template Lambdas)**：C++14 的 `auto` 参数无法在函数体内获取具体的类型名 `T`，C++20 引入了显式的模板 Lambda。
*   **默认构造与赋值**：无捕获的 Lambda 现在可以默认构造和赋值。
*   **废弃隐式捕获 `this`**：为了安全，`[=]` 不再隐式捕获 `this`，必须显式写出。
*   **未计算上下文中的 Lambda**：可以在 `decltype`、`sizeof` 等不执行代码的地方使用 Lambda。

**代码示例：**
```cpp
// 1. 模板 Lambda (可以在函数体内使用类型 T)
auto print_type_size = []<typename T>(const std::vector<T>& vec) {
    std::cout << "Element size: " << sizeof(T) << std::endl;
    T temp{}; // 可以在内部声明 T 类型的变量
};

// 2. 默认构造 (仅限无捕获的 Lambda)
auto lambda = []() { return 42; };
decltype(lambda) lambda2; // C++20 允许默认构造
lambda2 = lambda;         // C++20 允许赋值

// 3. 废弃隐式 this 捕获 (重要安全改进)
struct A {
    int x = 10;
    auto f() {
        // C++20 中，[=] 隐式捕获 this 被废弃 (deprecated)
        // 必须显式写 [=, this] 或 [=, *this]
        return [=, this]() { return x; }; 
    }
};

// 4. 未计算上下文
using FuncType = decltype([](int x) { return x * 2; });
constexpr size_t size = sizeof([]{ return 0; }); // 合法
```

---

### 💡 总结与最佳实践

1. **优先使用 `auto` 接收 Lambda**：
   除非你需要将其赋值给 `std::function`（有类型擦除的性能开销），否则永远使用 `auto` 来保存 Lambda，这样能保持其独特的闭包类型，性能最好。
2. **警惕引用捕获 `[&]` 的生命周期**：
   如果 Lambda 的生命周期长于被引用的变量（例如存入 `std::vector` 或作为异步回调），**绝对不要**使用 `[&]`，请使用 `[=]` 或 C++17 的 `[*this]`。
3. **C++20 的 `[=, this]` 习惯**：
   在 C++20 及以后，如果在成员函数中写 Lambda 且需要访问成员，请显式写出 `[=, this]` 或 `[this]`，避免编译警告，也让代码意图更清晰。
4. **需要类型萃取时，使用 C++20 模板 Lambda**：
   如果你需要在 Lambda 内部使用参数的具体类型（如 `std::is_same_v<T, int>`），放弃 C++14 的 `auto` 参数，改用 C++20 的 `[]<typename T>(T x)`。

*(注：如果你未来升级到 **C++23**，Lambda 还会支持 `auto(x)` 防止参数类型退化，以及通过 `operator()` 实现 Lambda 的递归调用，敬请期待！)*
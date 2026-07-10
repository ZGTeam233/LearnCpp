编写“接受可调用对象（Callable）的高阶函数”是 C++ 泛型编程和函数式编程的核心技能。

在 C++ 中，**可调用对象**包括：普通函数、函数指针、重载了 `operator()` 的类对象（Functor）、Lambda 表达式，以及 `std::function`。

要编写一个能优雅接受所有这些可调用对象的高阶函数，主要有**三种方式**。下面我为你从基础到进阶逐一拆解。

---

### 方案一：模板参数（👑 绝对的首选，零开销）
这是 C++ 中最标准、性能最高、最灵活的写法。通过模板，编译器会在编译期为每一种传入的可调用对象生成专属代码，**没有任何运行时开销**。

#### 基础示例：实现一个自定义的 `for_each`
```cpp
#include <iostream>
#include <vector>

// 模板参数 Func 接受任何可调用对象
template <typename Container, typename Func>
void my_for_each(Container& c, Func f) {
    for (auto& elem : c) {
        f(elem); // 调用传入的函数/lambda
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};

    // 1. 传入 Lambda
    my_for_each(nums, [](int n) { std::cout << n << " "; });
    
    // 2. 传入普通函数
    // void print(int n) { std::cout << n << " "; }
    // my_for_each(nums, print);
}
```

#### 进阶示例：带完美转发的计时器 (`measure_time`)
在真实工程中，高阶函数通常需要把参数**完美转发**给传入的可调用对象，并推导其返回值。

```cpp
#include <iostream>
#include <chrono>
#include <utility> // std::forward
#include <functional> // std::invoke (C++17)

// C++14 的 auto 返回类型推导
template <typename Func, typename... Args>
auto measure_time(Func f, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    
    // std::invoke 是 C++17 的神器，它能统一处理普通函数、Lambda、甚至成员函数指针
    // std::forward 完美转发参数，保留左值/右值属性
    decltype(auto) result = std::invoke(f, std::forward<Args>(args)...);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "耗时: " << duration.count() << " 微秒\n";
    
    return result; // 返回原函数的计算结果
}

int heavy_compute(int x) {
    return x * x;
}

int main() {
    // 传入普通函数和参数
    int res1 = measure_time(heavy_compute, 10);
    
    // 传入 Lambda 和参数
    int res2 = measure_time([](int a, int b) { return a + b; }, 5, 6);
}
```

---

### 方案二：`std::function`（类型擦除，灵活但有开销）
如果你需要把可调用对象**存储在类成员变量中**，或者放入**同一个容器（如 `std::vector`）** 里，模板就不够用了（因为每个 lambda 类型都不同）。这时必须使用 `std::function`。

**代价**：它会在运行时进行“类型擦除”，如果传入的 lambda 捕获了较多变量（超过了内部小对象优化的缓冲区），就会触发**堆内存分配（Heap Allocation）**，有性能损耗。

```cpp
#include <iostream>
#include <functional>
#include <vector>

// 明确指定签名：接受一个 int，返回 int
using IntToIntFunc = std::function<int(int)>;

void apply_transform(std::vector<int>& data, IntToIntFunc transformer) {
    for (auto& val : data) {
        val = transformer(val);
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    
    // 可以传入 Lambda
    apply_transform(nums, [](int x) { return x * 2; });
    
    // 可以传入普通函数
    // int add_one(int x) { return x + 1; }
    // apply_transform(nums, add_one);
}
```

---

### 方案三：C++20 Concepts（带约束的高阶函数）
在 C++20 之前，如果你用模板写高阶函数，当用户传入了一个**签名不对**的可调用对象时，编译器会报出长达几十行的恐怖模板错误。
C++20 引入了 **Concepts（概念）**，可以优雅地约束传入的可调用对象必须满足特定条件。

```cpp
#include <iostream>
#include <concepts>
#include <vector>

// 定义一个约束：Func 必须能够接受一个 int 参数，并且返回值可以转换为 double
template <typename Func>
concept IntToDoubleCallable = std::invocable<Func, int> && 
                              std::convertible_to<std::invoke_result_t<Func, int>, double>;

// 使用 concept 约束模板参数
void process_data(const std::vector<int>& data, IntToDoubleCallable auto func) {
    for (int n : data) {
        double result = func(n);
        std::cout << result << " ";
    }
}

int main() {
    // ✅ 合法：接受 int，返回 double
    process_data({1, 2, 3}, [](int x) -> double { return x / 2.0; });

    // ❌ 编译错误！概念约束失败：
    // process_data({1, 2, 3}, [](std::string s) { return 1.0; }); 
    // 编译器会直接报错：约束不满足，而不是报一堆模板推导错误。
}
```

---

### 🚨 避坑指南与最佳实践

#### 1. 永远优先使用模板，慎用 `std::function` 作为参数
```cpp
// ❌ 不推荐：作为函数参数时，std::function 会阻止内联，且有类型擦除开销
void do_something(std::function<void()> callback); 

// ✅ 推荐：使用模板，编译器能完美内联，零开销
template <typename Callback>
void do_something(Callback&& callback); 
```
**例外**：只有当你需要把 callback **存起来**（比如存到类的成员变量里，或者放进 `std::vector` 统一管理）时，才使用 `std::function`。

#### 2. 使用 `std::invoke` 代替直接调用 `f(args...)`
在 C++17 中，直接写 `f(args...)` 无法处理**成员函数指针**。使用 `std::invoke(f, obj, args...)` 可以统一处理普通函数、Lambda 和成员函数，代码更具泛型能力。

#### 3. 注意参数传递方式 (`const&` vs `&&`)
- 如果高阶函数只是**调用**这个可调用对象，不保存它：使用 `const Func&` 或 `Func&&`（配合完美转发）。
- 如果高阶函数需要**保存**这个可调用对象（比如存入类成员）：按值捕获 `Func f`，或者使用 `std::function`。

#### 4. 返回类型的推导
- **C++11**：必须用尾置返回类型 `-> decltype(f(args...))`。
- **C++14**：直接写 `auto`，编译器自动推导。
- **C++14+ 完美转发场景**：使用 `decltype(auto)`，确保如果原函数返回引用，高阶函数也返回引用，而不是被 `auto` 截断成值。

---

### 总结口诀
- **做算法/工具函数**：用 **模板 + `std::invoke` + `std::forward`**（性能最高）。
- **需要存起来/放进容器**：用 **`std::function`**（牺牲一点性能换取类型统一）。
- **C++20 及以后**：给模板加上 **`std::invocable` 等 Concepts**（错误提示更友好，接口更严谨）。

你想尝试手写一个类似 `std::transform` 或者 `retry`（失败重试）的高阶函数练练手吗？
既然你已经掌握了基础，那我们来点“现代 C++”的进阶挑战！

这道题将重点考察 **C++14 及以上版本** 引入的 Lambda 高级特性，包括 **`mutable` 关键字**、**泛型 Lambda（`auto` 参数）**、**初始化捕获（移动捕获）** 以及 **返回 Lambda 的高阶函数**。

### 题目名称：事件处理流水线

#### 题目背景
你正在为一个游戏引擎编写事件处理系统。你需要使用 Lambda 表达式来构建一系列灵活的事件处理器。

#### 任务要求
请补全下方的代码框架，完成 4 个特定的 Lambda 构建任务。
**注意**：本题需要使用 **C++14 或更高版本** 标准编译（如 gcc/clang 加上 `-std=c++14` 或更高，MSVC 默认支持）。

1. **带记忆的执行器（考察 `mutable`）**：
    - 创建一个 Lambda，按值捕获一个初始状态 `count = 0`。
    - 每次调用该 Lambda 时，将 `count` 增加 1，打印 `"Event processed: count = X"`（X为当前count值），并返回当前的 `count`。
    - **提示**：默认情况下，按值捕获的变量在 Lambda 内部是 `const` 的，你需要使用特定的关键字来修改它。

2. **泛型数据提取器（考察 泛型 Lambda）**：
    - 创建一个 Lambda，使用 `auto` 作为参数类型（C++14 特性）。
    - 它接收一个 `std::pair`（包含两个元素，类型任意），并返回该 `pair` 的**第二个元素**（`second`）。

3. **独占资源处理器（考察 初始化捕获/移动捕获）**：
    - 代码中提供了一个 `std::unique_ptr<std::string>` 指向字符串 `"SecretConfig"`。
    - 创建一个 Lambda，使用 C++14 的**初始化捕获**语法（形如 `[var = std::move(unique_ptr)]`）来获取这个 `unique_ptr` 的所有权。
    - Lambda 内部打印该指针指向的字符串内容。

4. **处理器工厂（考察 返回 Lambda 的 Lambda）**：
    - 编写一个普通函数（或 Lambda），名为 `createFilter`，接收一个整数阈值 `threshold`。
    - 它需要**返回一个新的 Lambda**。这个返回的 Lambda 接收一个整数 `x`，如果 `x > threshold` 则返回 `true`，否则返回 `false`。
    - 使用 `createFilter(50)` 生成的 Lambda 作为 `std::copy_if` 的条件，从给定的数组中筛选出大于 50 的数字。

#### 初始代码框架

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <iterator>
#include <utility>

using namespace std;

// TODO 4: 实现处理器工厂函数 createFilter
// 接收一个 int threshold，返回一个 Lambda


int main() {
    cout << "--- 任务 1: 带记忆的执行器 ---" << endl;
    // TODO 1: 创建带记忆的执行器 lambda
    // 提示: 需要用到 mutable 关键字
    // auto executor = ...
    
    // 调用 3 次 executor 进行测试
    // executor(); executor(); executor();


    cout << "\n--- 任务 2: 泛型数据提取器 ---" << endl;
    // TODO 2: 创建泛型提取器 lambda (使用 auto 参数)
    // auto extractor = ...
    
    pair<int, string> p1{1, "Apple"};
    pair<double, vector<int>> p2{3.14, {1, 2, 3}};
    
    // 测试提取器 (注意打印方式)
    // cout << extractor(p1) << endl;
    // cout << extractor(p2).size() << endl; // 假设提取出 vector，打印其大小


    cout << "\n--- 任务 3: 独占资源处理器 ---" << endl;
    auto config_ptr = make_unique<string>("SecretConfig");
    
    // TODO 3: 创建使用初始化捕获的 lambda
    // 提示: [config = std::move(config_ptr)]
    // auto resource_handler = ...
    
    // 调用 resource_handler 测试
    // resource_handler();
    
    // 验证所有权是否转移 (此时 config_ptr 应该为空)
    if (!config_ptr) {
        cout << "所有权已成功转移！" << endl;
    }


    cout << "\n--- 任务 4: 处理器工厂 ---" << endl;
    vector<int> numbers = {10, 60, 30, 80, 45, 90};
    vector<int> filtered_numbers;

    // TODO 4 续: 使用 createFilter(50) 返回的 lambda 作为 copy_if 的条件
    // copy_if(numbers.begin(), numbers.end(), back_inserter(filtered_numbers), ...);

    cout << "筛选结果 (>50): ";
    for (int num : filtered_numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

#### 预期输出
```text
--- 任务 1: 带记忆的执行器 ---
Event processed: count = 1
Event processed: count = 2
Event processed: count = 3

--- 任务 2: 泛型数据提取器 ---
Apple
3

--- 任务 3: 独占资源处理器 ---
Resource loaded: SecretConfig
所有权已成功转移！

--- 任务 4: 处理器工厂 ---
筛选结果 (>50): 60 80 90 
```

### 💡 核心难点提示
1. **任务 1**：如果你直接写 `[count = 0]() { count++; }`，编译器会报错。想想 C++ 是如何保证 Lambda 默认不可变性的，以及如何打破它。
2. **任务 2**：参数写成 `auto` 后，返回类型编译器能自动推导吗？
3. **任务 3**：`std::unique_ptr` 是不可拷贝的，只能移动。传统的 `[&ptr]` 或 `[ptr]` 都不行，必须使用 C++14 的 `=` 初始化捕获语法。
4. **任务 4**：注意 `createFilter` 内部的 Lambda 需要捕获外部的 `threshold`，它是按值捕获还是按引用捕获？为什么？

这道题做完，你对 C++ Lambda 的理解就能达到现代 C++ 进阶开发者的水平了。祝你挑战成功！写完可以发出来我帮你 Review。

---

这是一道为你量身定制的 C++ Lambda 表达式练习题，难度适中，主要考察 Lambda 在不同 STL 算法中的配合使用以及捕获列表的掌握。

### 题目名称：成绩处理小助手

#### 题目背景
你是一名助教，手头有一份学生的期末考试成绩单（用一个整数数组/`vector` 表示）。为了公平起见，你需要对成绩进行一系列自动化处理。

#### 任务要求
请补全下方的 C++ 代码框架，完成成绩的过滤、加分和排序工作。
**核心要求**：整个处理流程中，必须**至少使用 3 次 Lambda 表达式**，并且其中**至少有一次必须使用捕获列表（Capture List）**。

1. **筛选及格线**：使用第一个 Lambda 表达式，配合合适的 STL 算法，从原始成绩中筛选出所有及格（`>= 60` 分）的成绩，存入一个新的 `vector` 中。
2. **添加平时分**：使用第二个 Lambda 表达式，给及格的成绩加上“平时分”。
    - 平时分的值由外部变量 `bonus` 决定。
    - **注意**：这里必须使用 Lambda 的**捕获列表**来获取外部的 `bonus` 变量。
    - 加分后的总成绩最高不能超过 100 分。
3. **成绩排名**：使用第三个 Lambda 表达式，作为自定义比较器，对加分后的成绩进行**降序**排列（从高到低）。
4. **打印结果**：遍历最终的成绩并打印。

#### 初始代码框架
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    // 原始成绩
    std::vector<int> scores = {45, 88, 59, 72, 95, 60, 30, 82};
    
    // 外部变量：平时加分
    int bonus = 5; 

    std::vector<int> passed_scores;
    
    // TODO 1: 使用第一个 lambda 筛选及格成绩 (>= 60) 放入 passed_scores
    
    // TODO 2: 使用第二个 lambda 给 passed_scores 中的每个成绩加上 bonus，且最高不超过 100
    
    // TODO 3: 使用第三个 lambda 对 passed_scores 进行降序排序
    
    // 打印最终结果
    std::cout << "最终成绩: ";
    for (int score : passed_scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### 预期输出
```text
最终成绩: 100 93 87 77 65 
```
*(注：原始及格成绩为 88, 72, 95, 60, 82。加上 5 分后变为 93, 77, 100, 65, 87。降序排列后为 100, 93, 87, 77, 65)*

#### 提示
- 可以查阅 `<algorithm>` 库中的 `std::copy_if`、`std::transform` 和 `std::sort`。
- 思考一下，在第二个任务中，你是选择按值捕获 `[bonus]` 还是按引用捕获 `[&bonus]`？为什么？

祝你 coding 愉快！写完后可以自己编译运行测试一下。

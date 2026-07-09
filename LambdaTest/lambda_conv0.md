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

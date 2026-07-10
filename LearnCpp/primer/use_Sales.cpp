#include <iostream>
#include "Sales_data.h"
#include "Screen.h"
#include "../logutil/LogUtil.h"
#include "../core.h"

using namespace std;
using namespace primer;

int use_sales() {
    Sales_data total; // 保存和的变量
    cout << "<ISBN> <units_sold> <price>" << endl; // 提示输入格式
    // 读入第一笔交易，并确保有数据可以处理
    if (cin >> total) {
        Sales_data trans;

        // 读入剩余的交易
        while (cin >> trans) {
            // 如果我们仍在处理相同的书
            if (total.isbn() == trans.isbn())
                total.combine(trans); // 更新总销售额
            else {
                // 输出前一本书的结果
                cout << total << endl; // 打印结果并换行
                total = trans; // total现在表示下一本书的销售额
            }
        }
        cout << total << endl; // 输出最后一本书的结果
    } else {
        // 没有输入，给出提示
        LOG_ERROR(__FUNCTION__, "No data?");
        return -1;
    }
    return 0;
}
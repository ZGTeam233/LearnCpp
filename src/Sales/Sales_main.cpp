/*
 * Created by Zilin Zheng on 2026/4/4.
 * 免责声明见: ./Disclaimer.md
 */

#include <iostream>
#include "Sales_data.h"
#include "DebugErr.h"

using namespace std;

int main() {
    Sales_data total; // 保存和的变量

    // 读入第一笔交易，并确保有数据可以处理
    if (read(cin, total)) {
        Sales_data trans;
        cout << "<ISBN> <units_sold> <price>" << endl; // 提示输入格式

        // 读入剩余的交易
        while (read(cin, trans)) {
            // 如果我们仍在处理相同的书
            if (total.isbn() == trans.isbn())
                total.combine(trans); // 更新总销售额
            else {
                // 输出前一本书的结果
                print(cout, total) << endl; // 打印结果并换行
                total = trans; // total现在表示下一本书的销售额
            }
        }
        print(cout, total) << endl; // 输出最后一本书的结果
    } else {
        // 没有输入，给出提示
        print(cout, DebugErr('e', __FILE_NAME__, __FUNCTION__,__LINE__, "No data?"));
        return -1;
    }
    return 0;
}
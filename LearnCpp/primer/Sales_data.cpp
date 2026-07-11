#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

namespace primer {
    double Sales_data::avg_price() const {
        if (units_sold)
            return revenue / units_sold;
        else
            return 0;
    }

    Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
        units_sold += rhs.units_sold; // 叠加销售数量
        revenue += rhs.revenue; // 叠加销售收入
        return *this; // 返回对象本身
    }

    istream& operator>>(istream& is, Sales_data& item) {
        double price = 0;
        is >> item.bookNo >> item.units_sold >> price;
        if (is)
            item.revenue = price * item.units_sold;
        else
            item = Sales_data();
        return is;
    }

    ostream& operator<<(ostream& os, const Sales_data& item) {
        os << item.isbn() << " " << item.units_sold << " "
            << item.revenue << " " << item.avg_price();
        return os;
    }

    Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
        Sales_data sum = lhs; // 复制左操作数到sum中
        sum += rhs; // 将右操作数的数据添加到sum中
        return sum; // 返回sum
    }

    Sales_data::Sales_data(istream& is) {
        is >> *this; // 将is绑定到当前对象并从中读取数据
    }
} // primer
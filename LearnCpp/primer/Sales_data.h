#ifndef LEARNCPP_SALES_DATA_H
#define LEARNCPP_SALES_DATA_H

#include <iostream>
#include <string>

namespace primer {
    class Sales_data {
        friend Sales_data operator+(const Sales_data&, const Sales_data&);
        friend std::ostream& operator<<(std::ostream&, const Sales_data&);
        friend std::istream& operator>>(std::istream&, Sales_data&);

    public:
        // 构造函数
        Sales_data() = default;

        Sales_data(const std::string& s) : bookNo(s) {
        }

        Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
        }

        Sales_data(std::istream&);

        // 成员函数
        std::string isbn() const { return bookNo; }
        Sales_data& operator+=(const Sales_data&);

    private:
        // 作为实现细节的成员函数
        double avg_price() const;

        // 数据成员
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    };

    // Sales_data类的非成员接口
    Sales_data operator+(const Sales_data&, const Sales_data&);
    std::ostream& operator<<(std::ostream&, const Sales_data&);
    std::istream& operator>>(std::istream&, Sales_data&);
} // primer

#endif //LEARNCPP_SALES_DATA_H
#include "drug_database.h"
#include "query_app.h"
#include <iostream>
#include <windows.h>

int main() {
    DrugDatabase db;
    if (!db.loadFromFile("drugs_jp.txt")) {
        std::cerr << "无法打开 drugs_jp.txt，请先运行 gen_jp.py 生成数据文件。\n";
        return -1;
    }

    QueryApp app(db, std::cin, std::cout);
    app.run();
    return 0;
}

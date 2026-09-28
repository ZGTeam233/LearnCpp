#include "query_app.h"

QueryApp::QueryApp(DrugDatabase& db, std::istream& in, std::ostream& out)
    : db_(db), in_(in), out_(out) {}

void QueryApp::printBanner() const {
    out_ << "====================================\n"
        << "       中药首字母简拼查询系统\n"
        << "       已加载 " << db_.size() << " 味药材\n"
        << "       输入简拼查询，输入 q 退出\n"
        << "====================================\n";
}

void QueryApp::printResults(const DrugDatabase::SearchResult& results,
    const std::string& title) const {
    if (results.empty()) {
        out_ << title << "：无匹配结果。\n";
        return;
    }
    out_ << title << "（共 " << results.size() << " 条）：\n";
    for (const Drug* drug : results) {
        out_ << "  " << drug->name()
            << "  [" << drug->jianpin() << "]\n";
    }
}

bool QueryApp::handleQuery(const std::string& query) {
    const auto exact = db_.searchExact(query);
    if (!exact.empty()) {
        printResults(exact, "精确匹配");
        return true;
    }
    const auto fuzzy = db_.searchFuzzy(query);
    printResults(fuzzy, "模糊匹配");
    return !fuzzy.empty();
}

void QueryApp::run() {
    printBanner();

    std::string query;
    while (true) {
        out_ << "\n请输入简拼: ";
        if (!(in_ >> query)) break;
        if (query == "q" || query == "Q") break;
        handleQuery(query);
    }
    out_ << "再见！\n";
}
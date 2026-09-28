#pragma once

#include "drug_database.h"
#include <istream>
#include <ostream>
#include <string>

class QueryApp {
public:
    QueryApp(DrugDatabase& db, std::istream& in, std::ostream& out);

    void run();

private:
    void printBanner() const;
    void printResults(const DrugDatabase::SearchResult& results,
        const std::string& title) const;
    bool handleQuery(const std::string& query);

    DrugDatabase& db_;
    std::istream& in_;
    std::ostream& out_;
};

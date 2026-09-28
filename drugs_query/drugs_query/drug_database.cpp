#include "drug_database.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>

std::string DrugDatabase::toLower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return result;
}

bool DrugDatabase::loadFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) return false;

    drugs_.clear();
    index_.clear();

    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string jianpin;
        if (!(iss >> jianpin)) continue;

        std::string name;
        std::getline(iss, name);

        // È¥µôÇ°µ¼¿Õ°×
        const auto start = name.find_first_not_of(" \t");
        if (start == std::string::npos) continue;
        name = name.substr(start);

        const std::size_t idx = drugs_.size();
        drugs_.emplace_back(name, jianpin);
        index_[toLower(jianpin)].push_back(idx);
    }
    return true;
}

DrugDatabase::SearchResult
DrugDatabase::searchExact(const std::string& jianpin) const {
    SearchResult result;
    const auto it = index_.find(toLower(jianpin));
    if (it == index_.end()) return result;

    result.reserve(it->second.size());
    for (const auto idx : it->second) {
        result.push_back(&drugs_[idx]);
    }
    return result;
}

DrugDatabase::SearchResult
DrugDatabase::searchFuzzy(const std::string& jianpin) const {
    SearchResult result;
    const std::string key = toLower(jianpin);

    for (const auto& pair : index_) {
        if (pair.first.find(key) == std::string::npos) continue;
        for (const auto idx : pair.second) {
            result.push_back(&drugs_[idx]);
        }
    }

    std::sort(result.begin(), result.end(),
        [](const Drug* a, const Drug* b) {
            if (a->jianpin() != b->jianpin())
                return a->jianpin() < b->jianpin();
            return a->name() < b->name();
        });
    return result;
}

#pragma once

#include "drug.h"
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

class DrugDatabase {
public:
    using DrugList = std::vector<Drug>;
    using SearchResult = std::vector<const Drug*>;

    // 从 "简拼 药名" 格式的文件加载
    bool loadFromFile(const std::string& filename);

    // 精确匹配简拼
    SearchResult searchExact(const std::string& jianpin) const;

    // 模糊匹配（简拼包含查询串）
    SearchResult searchFuzzy(const std::string& jianpin) const;

    std::size_t size() const noexcept { return drugs_.size(); }

private:
    static std::string toLower(const std::string& s);

    DrugList drugs_;
    std::unordered_map<std::string, std::vector<std::size_t>> index_; // 简拼 -> 索引
};


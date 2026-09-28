#include "drug.h"

#include <algorithm>
#include <cctype>

namespace {
    std::string toLower(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        return s;
    }
} // namespace

Drug::Drug(std::string name, std::string jianpin)
    : name_(std::move(name)), jianpin_(toLower(std::move(jianpin))) {}

bool Drug::operator<(const Drug& other) const noexcept {
    return name_ < other.name_;
}
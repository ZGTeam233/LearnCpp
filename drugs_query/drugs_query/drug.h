#pragma once

#include <string>

class Drug {
public:
    Drug() = default;
    Drug(std::string name, std::string jianpin);

    const std::string& name()    const noexcept { return name_; }
    const std::string& jianpin() const noexcept { return jianpin_; }

    bool operator<(const Drug& other) const noexcept;

private:
    std::string name_;
    std::string jianpin_;   // ͳһ��Сд
};


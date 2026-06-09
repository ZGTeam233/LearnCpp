// Created by ZGTeam233 on 2026/6/9.

#include <iostream>
#include "DebugErr.h"

std::ostream &print(std::ostream &os, const DebugErr &err) {
    if (err.level.empty()) {
        std::cerr << "No data?" << std::endl;
        return os;
    }
    os << err.level << ": ";
    if (!err.file.empty()) {
        os << err.file << ":" << std::endl;
    }
    os << "\t" <<err.tag << " ";
    if (err.line)
        os << "at line " << err.line << std::endl;
    os << "\tCompiled on " << err.date << std::endl;
    os << "\t" << err.msg << std::endl;
    return os;
}

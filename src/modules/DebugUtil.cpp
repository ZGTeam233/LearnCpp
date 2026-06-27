// Created by ZGTeam233 on 2026/6/9.

#include <iostream>
#include "DebugUtil.hpp"
void DebugLog::printLog(const DebugErr &err) {
    if (!err.file.empty()) {
        std::cerr << err.file << ":" << std::endl;
    }
    std::cerr << "\t" <<err.tag << " ";

    /*
     * IDE别TM老烦我
     * 0代表未传行号，带line参数的构造会赋值非0值
     */
    if (err.line)
        std::cerr << "at line " << err.line << std::endl;
    std::cerr << "\tCompiled on " << __DATE__ << std::endl;
    std::cerr << "\t" << err.msg << std::endl;
}

void DebugLog::error(const DebugErr &err) {
    std::cerr << "Error: ";
    printLog(err);
}

void DebugLog::warn(const DebugErr &err) {
    std::cerr << "Warn: ";
    printLog(err);
}

void DebugLog::info(const DebugErr &err) {
    std::cerr << "Info: ";
    printLog(err);
}

void DebugLog::debug(const DebugErr &err) {
    std::cerr << "Debug: ";
    printLog(err);
}

void DebugLog::verbose(const DebugErr &err) {
    std::cerr << "Verbose: ";
    printLog(err);
}
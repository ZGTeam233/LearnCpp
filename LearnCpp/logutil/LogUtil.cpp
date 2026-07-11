//
// Created by wsnzg6 on 2026/6/9.
// Copyright(c) 2026 ZGTeam233.
//

#include <iostream>
#include "LogUtil.h"

using namespace std;

void LogUtil::printLog(ostream& os,
                       const string& level, const DebugError& err) {
    os << level << ": " << err.file << ":" << endl;
    os << "\t" << err.tag << " at line " << err.line << endl;
    os << "\tCompiled on " << __DATE__ << endl;
    os << "\t" << err.msg << endl;
}

void LogUtil::error(const DebugError& err) {
    if constexpr (level <= ERROR)
        printLog(cerr, "Error", err);
}

void LogUtil::warn(const DebugError& err) {
    if constexpr (level <= WARN)
        printLog(cerr, "Warn", err);
}

void LogUtil::info(const DebugError& err) {
    if constexpr (level <= INFO)
        printLog(cout, "Info", err);
}

void LogUtil::debug(const DebugError& err) {
    if constexpr (level <= DEBUG)
        printLog(cout, "Debug", err);
}

void LogUtil::verbose(const DebugError& err) {
    if constexpr (level <= VERBOSE)
        printLog(cout, "Verbose", err);
}
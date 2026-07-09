// Created by ZGTeam233 on 2026/6/9.

#ifndef LOGUTIL_H
#define LOGUTIL_H

#include <iostream>
#include <string>

class LogUtil {
public:
    struct DebugError {
        const std::string file, tag;
        const int line = 0;
        const std::string msg;
    }; // DebugErr

    static void error(const DebugError&);
    static void warn(const DebugError&);
    static void info(const DebugError&);
    static void debug(const DebugError&);
    static void verbose(const DebugError&);
private:
    static void printLog(std::ostream&, const std::string&, const DebugError&);
    static constexpr int VERBOSE = 0;
    static constexpr int DEBUG = 1;
    static constexpr int INFO = 2;
    static constexpr int WARN = 3;
    static constexpr int ERROR = 4;
    static constexpr int level = VERBOSE;
}; // LogUtil

#define LOG_ERROR(tag, msg) LogUtil::error({__FILE__, tag, __LINE__, msg})
#define LOG_WARN(tag, msg) LogUtil::warn({__FILE__, tag, __LINE__, msg})
#define LOG_INFO(tag, msg) LogUtil::info({__FILE__, tag, __LINE__, msg})
#define LOG_DEBUG(tag, msg) LogUtil::debug({__FILE__, tag, __LINE__, msg})
#define LOG_VERBOSE(tag, msg) LogUtil::verbose({__FILE__, tag, __LINE__, msg})

#endif //LOGUTIL_H

// Created by ZGTeam233 on 2026/6/9.

#ifndef DEBUG_UTIL_H
#define DEBUG_UTIL_H

#include <string>

#define MAKE_DEBUG_ERR(tag, msg) DebugErr(__FILE__, tag, __LINE__, msg)

class DebugLog;

class DebugErr {
friend DebugLog;
public:
    DebugErr(const std::string &f, const std::string &t, int ln,
            const std::string &m) : file(f), tag(t),
            line(ln), msg(m) {}
    DebugErr(const std::string &f, const std::string &t,
            const std::string &m) : DebugErr(f, t, 0, m) {}
    DebugErr(const std::string &t, const std::string &m) :
            DebugErr("", t, m) {}
private:
    const std::string file, tag;
    const int line = 0;
    const std::string msg;
};

class DebugLog {
public:
    static void error(const DebugErr&);
    static void warn(const DebugErr&);
    static void info(const DebugErr&);
    static void debug(const DebugErr&);
    static void verbose(const DebugErr&);
private:
    static void printLog(const DebugErr&);
};

#endif //DEBUG_UTIL_H

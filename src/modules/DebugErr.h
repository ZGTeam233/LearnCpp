// Created by ZGTeam233 on 2026/6/9.

#ifndef DEBUG_ERR_H
#define DEBUG_ERR_H

#include <iostream>
#include <string>
#include <map>

class DebugErr {
friend std::ostream &operator<<(std::ostream&, const DebugErr&);
public:
    DebugErr() = default;
    DebugErr(char lv, const std::string &f, const std::string &t, int ln,
            const std::string &m) : level(errLevels[lv]), file(f), tag(t),
            line(ln), msg(m) {}
    DebugErr(char lv, const std::string &f, const std::string &t,
            const std::string &m) : DebugErr(lv, f, t, 0, m) {}
    DebugErr(char lv, const std::string &t, const std::string &m) :
            DebugErr(lv, "", t, 0, m) {}
private:
    inline static std::map<char, std::string> errLevels = {
        {'e', "Error"},
        {'w', "Warn"},
        {'i', "Info"},
        {'d', "Debug"},
        {'v', "Verbose"}
    };
    std::string level, file, tag;
    int line = 0;
    std::string msg;
};
std::ostream &operator<<(std::ostream&, const DebugErr&);

#endif //DEBUG_ERR_H

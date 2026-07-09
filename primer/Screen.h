#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

namespace primer {
    class Window_mgr;

    class Screen {
        // Window_mgr 的成员可以访问 Screen 类的私有部分
        friend class Window_mgr;
    public:
        typedef std::string::size_type pos;

        Screen() = default;
        Screen(pos ht, pos wd, char c): height(ht), width(wd),
            contents(ht * wd, c) {}
        Screen(pos ht, pos wd): Screen(ht, wd, ' ') {}

        char get() const {
            return contents[cursor]; // 读取光标处的字符
        }

        inline char get(pos, pos) const; // 声明处 inline
        Screen &move(pos, pos); // 定义处 inline

        void some_member() const;

        Screen &set(char);
        Screen &set(pos, pos, char);

        Screen &display(std::ostream &os) {
            do_display(os);
            return *this;
        }

        const Screen &display(std::ostream &os) const {
            do_display(os);
            return *this;
        }

    private:
        pos cursor = 0; // 光标位置
        pos height = 0, width = 0;
        std::string contents;
        mutable size_t access_ctr = 0; // 即使在一个 const 对象内也能被修改
        void do_display(std::ostream&) const;
    }; // Screen

    class Window_mgr {
    public:
        // 窗口中每个屏幕的编号
        using ScreenIndex = std::vector<Screen>::size_type;

        // 按照编号将指定的 Screen 充重置为空白
        void clear(ScreenIndex);
    private:
        /**
         * 表示这个 Window_mgr 追踪的 Screen
         * 默认情况下，一个 Window_mgr 包含一个
         * 标准尺寸的空白 Screen
         */
        std::vector<Screen> screens{Screen(24, 80, ' ')};
    }; // Window_mgr

#ifndef NDEBUG
    std::ostream &operator<<(std::ostream&, const Screen&);
#endif // NDEBUG

    // 内联函数一定要在头文件中定义

    // 定义处 inline
    inline Screen &Screen::move(pos r, pos c) {
        pos row = r * width; // 计算行的位置
        cursor = row + c;
        return *this;
    }

    // 声明处 inline
    char Screen::get(pos r, pos c) const {
        pos row = r * width;
        return contents[row + c];
    }

    inline Screen &Screen::set(char c) {
        contents[cursor] = c;
        return *this;
    }

    inline Screen &Screen::set(pos r, pos col, char ch) {
        contents[r * width + col] = ch;
        return *this;
    }
} // primer

#endif // SCREEN_H
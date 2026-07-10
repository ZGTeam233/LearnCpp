#include "Screen.h"

using namespace std;

namespace primer {
    void Screen::some_member() const {
        ++access_ctr; // 记录方法调用的次数
    }

    void Screen::do_display(ostream &os) const {
        // 边界检查：防止 width 为 0 时发生除零错误或 substr 异常
        if (! this->width) return;
        // 按行输出：利用 substr 每次截取 width 个字符
        for (pos r = 0; r != this->height; ++r) {
            // r * this->width 是当前行的起始索引，this->width 是截取长度
            os << this->contents.substr(r * this->width, this->width) << '\n';
        }
    }

    void Window_mgr::clear(ScreenIndex i) {
        // s 是一个 Screen 的引用，指向我们想清空的那个屏幕
        Screen &s = screens[i];

        // 将那个选定的 Screen 重置为空白
        s.contents = string(s.height * s.width, ' ');
    }

    Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
        screens.push_back(s);
        return screens.size() - 1;
    }

    void Screen::dummy_fcn(pos ht) {
        cursor = width * height;
    }
} // primer
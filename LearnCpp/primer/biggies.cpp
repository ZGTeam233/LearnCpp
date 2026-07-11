//
// Created by wsnzg6 on 2026/7/10.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace primer {
    string make_plural(size_t ctr, const string& word, const string& ending) {
        return (ctr > 1) ? word + ending : word;
    }

    void elimDups(vector<string>& words) {
        sort(words.begin(), words.end());
        auto end_unique = unique(words.begin(), words.end());
        words.erase(end_unique, words.end());
    }

    // 按长度和字典序排序
    void sort_words(vector<string>& words) {
        elimDups(words);
        stable_sort(words.begin(), words.end(),
                    [](const string& a, const string& b) {
                        return a.size() < b.size();
                    });
    }

    void biggies(vector<string>& words, vector<string>::size_type sz) {
        sort_words(words);

        // 计算满足 size >= sz 的元素数目
        auto wc = find_if(words.begin(), words.end(),
                          [sz](const string& a) {
                              return a.size() >= sz;
                          });
        auto count = words.end() - wc;
        cout << count << " " << make_plural(count, "word", "s")
            << " of length " << sz << " or longer" << endl;
        for_each(wc, words.end(),
                 [](const string& s) {
                     cout << s << " ";
                 });
        cout << endl;
    }
} // primer
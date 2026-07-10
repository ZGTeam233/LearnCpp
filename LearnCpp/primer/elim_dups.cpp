//
// Created by wsnzg6 on 2026/7/10.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace primer {
    void elimDups(vector<string> &words) {
        sort(words.begin(), words.end());
        auto end_unique = unique(words.begin(), words.end());
        words.erase(end_unique, words.end());
    }
} // primer
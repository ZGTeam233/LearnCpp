//
// Created by wsnzg6 on 2026/7/10.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "elim_dups.h"
#include "../core.h"

using namespace std;
using namespace primer;

void use_elim() {
    vector<string> words{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);
    for (const auto &s: words) {
        cout << s << " ";
    }
    cout << endl;
}
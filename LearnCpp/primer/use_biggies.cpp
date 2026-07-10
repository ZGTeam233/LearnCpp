//
// Created by wsnzg6 on 2026/7/10.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "biggies.h"
#include "../core.h"

using namespace std;
using namespace primer;

vector<string> words{
    "the", "quick", "red", "fox", "jumps",
    "over", "the", "slow", "red", "turtle"
};

void use_sort() {
    sort_words(words);
    for (const auto &s: words) {
        cout << s << " ";
    }
    cout << endl;
}

void use_biggies() {
    biggies(words, 4);
}
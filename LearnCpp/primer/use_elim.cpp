//
// Created by wsnzg6 on 2026/7/10.
//

#include <iostream>
#include <string>
#include <vector>
#include "elim_dups.h"
#include "../core.h"

using namespace std;
using namespace primer;

void use_elim() {
    vector<string> story{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    elimDups(story);
    for (string word: story) {
        cout << word << " ";
    }
    cout << endl;
}
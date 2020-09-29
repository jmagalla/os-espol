#include <random>
#include <vector>
#include <iostream>
#include "utils.h"
using namespace std;

mt19937 mt(1027);

int random_uniform(int l)
{
    uniform_int_distribution<int> dist(0, l);
    return dist(mt);
}

vector<string> readAllStrings() {
    string line;
    vector<string> words;
    while (getline(cin, line))
        words.push_back(line);

    return words;
}

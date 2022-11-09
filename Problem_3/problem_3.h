#ifndef MAIN_CPP_PROBLEM_3_H
#define MAIN_CPP_PROBLEM_3_H

#include<bits/stdc++.h>

using namespace std;
class StringSet
{
private:
    vector<string> vec;
public:
    StringSet() = default;
    StringSet(fstream file);
    StringSet(string s);
    void Add(string add);
    void Remove(string rem);
    void clear();
    int num_of_set();
    void print();
    StringSet operator+ (StringSet other);
    StringSet operator* (StringSet other);
    double similarity(StringSet Q,StringSet D);
    void divide(string &s);
};
#endif

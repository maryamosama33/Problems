

#ifndef MAIN_CPP_LABELGENERATOR_H
#define MAIN_CPP_LABELGENERATOR_H
#include<iostream>
#include<string>
using namespace std;

class LabelGenerator {
private:
    string name;
    int index;
public:
    LabelGenerator();
    LabelGenerator(string s,int in);
    virtual string nextLabel();
    string getName();
    int getIndex();
    friend ostream &operator << (ostream &out, LabelGenerator obj);
};


#endif //MAIN_CPP_LABELGENERATOR_H

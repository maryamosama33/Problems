
#include "LabelGenerator.h"

// default constructor
LabelGenerator::LabelGenerator(){
    name = "";
    index = 0;
}

//parameterized constructor
LabelGenerator::LabelGenerator(string s,int in){
    name = s;
    index = in;
}

// next index of the figure
string LabelGenerator::nextLabel() {
    string s = "";
    s = name + to_string(index++);
    return s;
}

/*
string LabelGenerator::getName() {
    return name;
}
*/

int LabelGenerator::getIndex() {
    return index;
}

/*
ostream &operator << (ostream &out, LabelGenerator obj) {
    out<<obj.getName()<<obj.getIndex();
    return out;
}
*/
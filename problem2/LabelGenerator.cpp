
#include "LabelGenerator.h"
LabelGenerator::LabelGenerator(){
    name="";
    index=0;
}

LabelGenerator::LabelGenerator(string s,int in){
    name=s;
    index=in;
}

string LabelGenerator::nextLabel() {
    string s="";
    s=name+ to_string(index++);
    return s;
}


string LabelGenerator::getName() {
    return name;
}

int LabelGenerator::getIndex() {
    return index;
}


ostream &operator << (ostream &out, LabelGenerator obj) {
    out<<obj.getName()<<obj.getIndex();
    return out;
}

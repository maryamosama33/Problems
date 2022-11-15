
#include "FileLabelGenerator.h"

// default constructor to make the file empty
FileLabelGenerator::FileLabelGenerator() {
    ofstream file(fileName);
    while(!file.eof()){
        file<<"";
    }

}

// overriding function nextLabel in the child class
string FileLabelGenerator::nextLabel() {

    string s="";
    s+=LabelGenerator::nextLabel()+" "+v[getIndex()-1];

    //  s+=LabelGenerator::nextLabel()+" "+v[getIndex()];

    return s;
}

/*
ostream &operator << (ostream &out, FileLabelGenerator obj) {
    //out << obj.getName() << obj.getIndex();
    out<<obj.nextLabel();
    return out;
}
*/

#include "FileLabelGenerator.h"

FileLabelGenerator::FileLabelGenerator() {
    ofstream file(fileName);
    while(!file.eof()){
        file<<"";
    }

}

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
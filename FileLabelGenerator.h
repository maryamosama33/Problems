
#ifndef MAIN_CPP_FILELABELGENERATOR_H
#define MAIN_CPP_FILELABELGENERATOR_H

#include "LabelGenerator.h"

#include <fstream>
#include<vector>

class FileLabelGenerator : public LabelGenerator{

private:
    string fileName;
    vector<string>v;

public:
    FileLabelGenerator();

    FileLabelGenerator(string s,int in,string F_name) : LabelGenerator( s, in) {
        fileName = F_name;
        ifstream file(fileName);
        if (file.fail()) {
            cout << "error ";
            exit(0);
        }
        string line;
        while(getline(file,line)) {
            v.push_back(line);
        }
    }
    string nextLabel();
    friend ostream &operator << (ostream &out, LabelGenerator obj);
};


#endif //MAIN_CPP_FILELABELGENERATOR_H

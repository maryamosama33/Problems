#include<bits\stdc++.h>
#include "LabelGenerator.h"
#include "FileLabelGenerator.h"
using namespace std;
int main(){

    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);

    cout << endl;
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl;
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";
    }
    cout << endl;
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl;
    cout<<"-----------------------------------------------------------------";
    cout<<endl;
    FileLabelGenerator figureLabels("Figure ", 1, "problem2.txt");
    cout << "Figure labels of file: \n";
    cout<<endl;
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
        cout<<endl;

    }
}

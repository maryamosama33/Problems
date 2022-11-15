//
// Created by 101 on 11/2/2022.
//

#ifndef MAIN_CPP_UNIVERSE_H
#define MAIN_CPP_UNIVERSE_H

#include<bits\stdc++.h>
#include<fstream>
#include<string>
#include "conio.h"
using namespace std;

#define SIZE1 20
#define SIZE2 20

class Universe {
private:
    bool grid[SIZE1+2][SIZE2+2]={{false}};
public:
    Universe(string file_name);
    void reset();
    int count_neighbors(int x,int y);
    void next_generation();
    void display();
    void run(int N_times);
};


#endif //MAIN_CPP_UNIVERSE_H

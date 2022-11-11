//
// Created by 101 on 11/2/2022.
//

#include "Universe.h"

Universe::Universe(string file_name) {
    ifstream file(file_name);
    for(int i=1;i<SIZE1+1;i++){
        for(int j=1;j<SIZE2+1;j++){
            file>>grid[i][j];
        }
    }
}

void Universe::display() {
    for(int i=1;i<SIZE1+1;i++){
        for(int j=1;j<SIZE2+1;j++){
                cout<<(grid[i][j] ? "L" : ".");
        }
        cout<<endl;
    }
}

int Universe::count_neighbors(int x,int y) {
    int sum = -grid[x][y];
    for(int i=x-1; i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            sum+=grid[i][j];
        }
    }
    return sum;
}

void Universe::next_generation() {

    bool new_grid[SIZE1+2][SIZE2+2]={{false}};

    for(int i=0;i<SIZE1+1;i++){
        for(int j=1;j<SIZE2+1;j++){

            int n_neighbors= count_neighbors(i,j);

            if(grid[i][j]==true){
                if(n_neighbors==2 || n_neighbors==3){
                    new_grid[i][j]=true;
                }
                else{
                    new_grid[i][j]==false;
                }
            }
            else{
                if(n_neighbors==3){
                    new_grid[i][j]= true;
                }
                else{
                    new_grid[i][j]=false;
                }

            }
        }
    }
    for(int i=1;i<SIZE1+1;i++) {
        for (int j = 1; j < SIZE2 + 1; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void Universe::run(int N_times) {
    for(int i=1;i<=N_times;i++){
        system("CLS");

        cout<<"Generation "<<i<<" of "<<N_times<<endl;
        next_generation();
        display();
        if(i==N_times)
            break;
        system("pause");
    }
}

void Universe::reset() {
   for (int i = 1; i < SIZE1 + 1; i++) {
        for (int j = 1; j < SIZE2 + 1; j++) {
            grid[i][j] = false;
        }
    }
}

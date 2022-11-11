#include<bits\stdc++.h>
#include"Universe.h"
#include "conio.h"
using namespace std;
int main() {
    Universe game("GameOfLife.txt");
    int n;
    cout<<"enter number of times you will play the game : ";
    cin>>n;
    game.run(n);
    // if you want to restet the board to zeros uncomment the following code
    // game.reset();
    // game.display();
}

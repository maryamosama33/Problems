#include"header.h"


// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board_f[x][y] == 0)) {
        board_f[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void Board::display_board() {
    for (int i: {0,1,2}) {
        cout << "\n| ";
        for (int j: {0,1,2}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board_f [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board_f[i][0] & board_f[i][1] & board_f[i][2];
        col_win[i] = board_f[0][i] & board_f[1][i] & board_f[2][i];
    }
    diag_win[0] = board_f[0][0] & board_f[1][1] & board_f[2][2];
    diag_win[1] = board_f[2][0] & board_f[1][1] & board_f[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == board_f[i][0])) ||
             (col_win[i] && (col_win[i] == board_f[0][i])) )
        {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board_f[1][1]) ||
        (diag_win[1] && diag_win[1] == board_f[1][1]))
    {return true;}
    return false;
}

// Return true if 9 moves are done and no winner
bool Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}


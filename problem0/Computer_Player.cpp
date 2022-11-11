#include"header.h"

//Name: Maryam osama mohamed  //ID: 20211090

// Give player a symbol to use in playing
ComputerPlayer ::ComputerPlayer(char symbol)
{
    this->symbol = symbol;
}

//function to check if there ara moves in board.
bool ComputerPlayer::is_valid(char board[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]==0)
                return true;
    return false;
}

int ComputerPlayer::evaluate(char b[3][3])
{
    for (int i = 0; i<3; i++)
    {
        if (b[i][0]==b[i][1] && b[i][1]==b[i][2])
        {
            if (b[i][0]=='O')
                return +10;
            else if (b[i][0]=='X')
                return -10;
        }
    }

    for (int i = 0; i<3; i++)
    {
        if (b[0][i]==b[1][i] && b[1][i]==b[2][i])
        {
            if (b[0][i]=='O')
                return +10;

            else if (b[0][i]=='X')
                return -10;
        }
    }

    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]=='O')
            return +10;
        else if (b[0][0]=='X')
            return -10;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]=='O')
            return +10;
        else if (b[0][2]=='X')
            return -10;
    }
    return 0;
}
//considers all the possible ways
int ComputerPlayer::minimax(char board[3][3], int d, bool Max)
{
    int score = evaluate(board);

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (!is_valid(board))
        return 0;

    if (Max)
    {
        int best = -1000;


        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]==0)
                {
                    board[i][j] = 'O';
                    best = max( best,minimax(board, d+1, !Max) );
                    board[i][j] = 0;
                }
            }
        }
        return best;
    }

    else
    {
        int best = 1000;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j]==0)
                {
                    board[i][j] = 'X';
                    best = min(best,minimax(board, d+1, !Max));
                    board[i][j] = 0;
                }
            }
        }
        return best;
    }
}
//function to return the best move.
Move ComputerPlayer:: BestMove(char board[3][3])
{
    int best = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (board[i][j]==0)
            {
                board[i][j] = 'O';
                int move = minimax(board, 0, false);
                board[i][j] = 0;
                if (move > best)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    best = move;
                }
            }
        }
    }
    return bestMove;
}
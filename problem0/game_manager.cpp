#include"header.h"


void GameManager::run() {
    Board x_o;
    int x, y;
    Player player1= {Player (1, 'X')};
    ComputerPlayer player2('O');
    x_o.display_board();
    while (true) {
        for (int i:{0,1})
        {
            if(i==0)
            {
                player1.get_move(x, y);
                while (!x_o.update_board (x, y, player1.get_symbol())){
                    player1.get_move(x, y);
                }
            }
            else if(i==1)
            {
                Move bestMove = player2.BestMove(x_o.board_f);
                x_o.update_board (bestMove.row, bestMove.col, player2.get_symbol());
            }
            x_o.display_board();
            if (x_o.is_winner()&&i==0){
                cout  << player1.to_string() << " wins\n";
                return;
            }
            if(x_o.is_winner()&&i==1)
            {
                cout  << "computer "<< " wins\n";
                return;
            }
            if (x_o.is_draw()){
                cout << "Draw!\n";
                return;

            }
        }
    }
}

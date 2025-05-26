#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "../../IGame.h"
#include <stdio.h>
#include <stdbool.h>

namespace game {
    class TicTacToe : public IGame {
    public:

        bool isPlaying;
        // 3x3 ���� ����
        char board[3][3];

        // ���� �÷��̾� ('X' �Ǵ� 'O')
        char currentPlayer;

        
        void game_init() override;
        void game_start() override;
        void game_over() override;
        void key_input(char key_code) override;
        std::string get_game_name() const override;

    private:
        void initializeBoard();
        void printBoard() const;
        bool checkWin() const;
        bool checkDraw() const;
        bool makeMove(int position);
        void switchPlayer();
    };

}

#endif
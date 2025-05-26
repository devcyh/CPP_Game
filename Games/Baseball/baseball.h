#ifndef BASEBALL_H
#define BASEBALL_H

#include "../../IGame.h"
#include <iostream>

#define FINAL_COUNT 5 // 10번까지 가능    

namespace game {
    class Baseball : public IGame {
    public:

        int gameOver; // 1이 되면 게임이 끝남   
        int usr_ball[3]; // 사용자가 입력한 값   
        int usr_ball_idx;
        int com_ball[3]; // 컴퓨터가 발생시킨 난수값  
        int strike_cnt; // 스트라이크 카운트   
        int ball_cnt; // 볼 카운트   
        int input_cnt; // 입력 횟수 카운 

        void game_init() override;
        void game_start() override;
        void game_over() override;
        void key_input(char key_code) override;
        std::string get_game_name() const override;

    private:
        bool calc();
    };

}

#endif
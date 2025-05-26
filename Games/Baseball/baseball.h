#ifndef BASEBALL_H
#define BASEBALL_H

#include "../../IGame.h"
#include <iostream>

#define FINAL_COUNT 5 // 10������ ����    

namespace game {
    class Baseball : public IGame {
    public:

        int gameOver; // 1�� �Ǹ� ������ ����   
        int usr_ball[3]; // ����ڰ� �Է��� ��   
        int usr_ball_idx;
        int com_ball[3]; // ��ǻ�Ͱ� �߻���Ų ������  
        int strike_cnt; // ��Ʈ����ũ ī��Ʈ   
        int ball_cnt; // �� ī��Ʈ   
        int input_cnt; // �Է� Ƚ�� ī�� 

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
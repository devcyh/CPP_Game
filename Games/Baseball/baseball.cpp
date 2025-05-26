#include "baseball.h"
 
using namespace std;

void game::Baseball::game_init() {
    this->gameOver = 0; // 1이 되면 게임이 끝남
    input_cnt = 1; // 입력 횟수 카운
    usr_ball_idx = 0;

    srand((unsigned int)time(0)); // 랜덤한 숫자를 발생시킨후   
    com_ball[0] = (rand() % 9) + 1; // 1~9 사이의 값으로 조절후 com_ball[0] 에넣습니다.     
    com_ball[1] = (rand() % 9) + 1;
    com_ball[2] = (rand() % 9) + 1;

    cout << "답: " << com_ball[0] << com_ball[1] << com_ball[2] << endl;
}
void game::Baseball::game_start() {
    cout << "야구 게임" << endl << endl;
    cout << "[" << input_cnt << "] 숫자 3개를 입력하세요. : ";
};
void game::Baseball::game_over() {};

bool game::Baseball::calc() {
    strike_cnt = 0;
    ball_cnt = 0;
    int comp[9] = { 0 };
    for (int i = 0; i < 3; i++) {
        if (com_ball[i] == usr_ball[i]) strike_cnt++;
        else {
            comp[com_ball[i]]++;
        }
    }
    if (strike_cnt == 3) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        if (comp[usr_ball[i]] > 0) {
            comp[usr_ball[i]]--;
            ball_cnt++;
        }
    }
    return false;
}
void game::Baseball::key_input(char key_code) {
    if (!key_code) return;
    if (!gameOver) {
        if (key_code < '0' || '9' < key_code) {
            cout << "숫자를 입력하세요." << endl;
            return;
        }
        usr_ball[usr_ball_idx] = key_code - '0';
        cout << usr_ball[usr_ball_idx++];
        
        if (usr_ball_idx == 3) {
            cout << endl;
            cout << "입력한 숫자는 " << usr_ball[0] << ", " << usr_ball[1] << ", " << usr_ball[2] << "입니다." << endl;
            if (!calc()) {
                input_cnt++;
                cout << "결과 : " << strike_cnt << " strike " << ball_cnt << " ball" << endl << endl;

                if (input_cnt == FINAL_COUNT) {
                    gameOver = 1;
                    cout << FINAL_COUNT << "회가 지나서 게임을 종료합니다." << endl;
                    return;
                }
                cout << "[" << input_cnt << "] 숫자 3개를 입력하세요. : ";
                usr_ball_idx = 0;
            }
            else {
                gameOver = 1;
                cout << "이겼습니다. ESC를 누르세요" << endl;
                return;
            }
        }
    }
};

std::string game::Baseball::get_game_name() const {
    return "Baseball";
};
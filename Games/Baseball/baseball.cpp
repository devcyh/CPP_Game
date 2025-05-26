#include "baseball.h"
 
using namespace std;

void game::Baseball::game_init() {
    this->gameOver = 0; // 1�� �Ǹ� ������ ����
    input_cnt = 1; // �Է� Ƚ�� ī��
    usr_ball_idx = 0;

    srand((unsigned int)time(0)); // ������ ���ڸ� �߻���Ų��   
    com_ball[0] = (rand() % 9) + 1; // 1~9 ������ ������ ������ com_ball[0] ���ֽ��ϴ�.     
    com_ball[1] = (rand() % 9) + 1;
    com_ball[2] = (rand() % 9) + 1;

    cout << "��: " << com_ball[0] << com_ball[1] << com_ball[2] << endl;
}
void game::Baseball::game_start() {
    cout << "�߱� ����" << endl << endl;
    cout << "[" << input_cnt << "] ���� 3���� �Է��ϼ���. : ";
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
            cout << "���ڸ� �Է��ϼ���." << endl;
            return;
        }
        usr_ball[usr_ball_idx] = key_code - '0';
        cout << usr_ball[usr_ball_idx++];
        
        if (usr_ball_idx == 3) {
            cout << endl;
            cout << "�Է��� ���ڴ� " << usr_ball[0] << ", " << usr_ball[1] << ", " << usr_ball[2] << "�Դϴ�." << endl;
            if (!calc()) {
                input_cnt++;
                cout << "��� : " << strike_cnt << " strike " << ball_cnt << " ball" << endl << endl;

                if (input_cnt == FINAL_COUNT) {
                    gameOver = 1;
                    cout << FINAL_COUNT << "ȸ�� ������ ������ �����մϴ�." << endl;
                    return;
                }
                cout << "[" << input_cnt << "] ���� 3���� �Է��ϼ���. : ";
                usr_ball_idx = 0;
            }
            else {
                gameOver = 1;
                cout << "�̰���ϴ�. ESC�� ��������" << endl;
                return;
            }
        }
    }
};

std::string game::Baseball::get_game_name() const {
    return "Baseball";
};
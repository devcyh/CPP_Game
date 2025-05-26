#include "../inc/Cabinet.h"

void Cabinet::hw_check() { };

void Cabinet::show_game_intro(int num_game, std::string* game_list) {

    system("cls");  // 화면 초기화

    COORD pos;

    pos.X = 5;
    pos.Y = 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << "=================Select the Game Title=================\n" << "\n           Up: ↑      Down : ↓      Select : s      Exit : ESC";

    for (int i = 0; i < num_game; i++) {
        pos.X = 10;
        pos.Y = 2 * i + 8;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

        std::cout << "[" << i+1 << "]   " << game_list[i];
    }

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

}

void Cabinet::choose_game(int num_games, std::string* game_list, int& index_game) {
    COORD pos;
    int choose_key;

    show_game_intro(num_games, game_list);
    
    pos.X = 8;
    pos.Y = 8;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << "▶";

    while(true) {
        choose_key = _getch();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        std::cout << "  ";

        if (choose_key == EXT_CODE_2) {
            choose_key = _getch();
            switch (choose_key)
            {
            case KEY_UP:
                pos.Y = max(8, pos.Y - 2);
                pos.Y = min(2*num_games+6, pos.Y);
                break;
            case KEY_DOWN:
                pos.Y = max(8, pos.Y + 2);
                pos.Y = min(2 * num_games + 6, pos.Y);
                break;
            default:
                break;
            }
        }
        else if ((choose_key == KEY_S)|| (choose_key == KEY_s)) {
            break;
        }
        else if (choose_key == KEY_ESC) {
            break;
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        std::cout << "▶";
    }
    if (choose_key == KEY_ESC) {
        index_game = -1;
    }
    else {
        index_game = (((pos.Y - 6) / 2) - 1);
    }
    system("cls");  // 화면 초기화
}

void Cabinet::load_game(IGame* game) {
    installed_game = game;
    //std::cout << "LOAD..." << std::endl;
};
void Cabinet::unload_game() {
    //delete installed_game;
    //installed_game = nullptr;
    //std::cout << "unload..." << std::endl;
};
void Cabinet::game_init() {
    if (installed_game) {
        installed_game->game_init();
        //std::cout << "init..." << std::endl;
    }
    else {
        //std::cout << "fail of init..." << std::endl;
    }
};

void Cabinet::game_start() {
    if (installed_game) {
        installed_game->game_start();

        is_running = true;
        while (is_running) {
            //std::cout << "start..." << std::endl;
            char key;
            if (_kbhit()) {
                key = _getch();
            }
            else {
                key = NULL;
            }
            if (key == KEY_ESC) {
                is_running = false;
            }
            installed_game->key_input(key);
        }
    }
};

#ifndef __CABINET_H__
#define __CABINET_H__

#include "../../IGame.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

//up,down,left,right
#define EXT_CODE_1		(0x00) // EXT=00.. F1, F2, F3
#define EXT_CODE_2		(0xE0) // EXT=E0.. Up, Down, Left, Right..
//Up, Down, Left, Right
#define KEY_UP          (0x48)
#define KEY_DOWN        (0x50)
//ESC
#define KEY_ESC         (0x1B)
//Select
#define KEY_S           (0x53)
#define KEY_s			(0x73)


class Cabinet {
    const char* cabinet_model_str = "Cabinet R123";
    IGame* installed_game = nullptr;
    bool is_running = false;

public:
    void hw_check();
    void show_game_intro(int num_games, std::string* game_list);
    void choose_game(int num_games, std::string* game_list, int& number_of_game);
    void load_game(IGame* game);
    void unload_game();
    void game_init();
    void game_start();
};

#endif // !__CABINET_H__
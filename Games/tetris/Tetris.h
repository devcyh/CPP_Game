#pragma once

#include <iostream>
#include <cstdint>
#include <ctime>
//#include <mmsystem.h>

extern "C" {
#include "core/inc/blocks.h"
#include "driver/inc/key_driver.h"
#include "driver/inc/cell.h"
#include "core/inc/board.h"
#include "model.h"
}

#include "../../IGame.h"

#pragma comment(lib, "winmm.lib") // winmm 라이브러리 링크

#define BOARD_START_X (4)
#define BOARD_START_Y (4)

class Tetris : public IGame {
private:
	// 전체 보드 전역 변수
	cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH] = { 0, };
	windows_console_t console;
	block_t my_block;

	// 블럭의 초기 정보를 갖고 있는 데이터
	cell_attributes_t board_data_attributes[BOARD_HEIGHT][BOARD_WIDTH] = {
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (0,0),(0,1),(0,2),(0,3),(0,4),(0,5),(0,6),(0,7),(0,8),(0,9),(0,10),(0,11)
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (1,0),(1,1),(1,2),(1,3),(1,4),(1,5),(1,6),(1,7),(1,8),(1,9),(1,10),(1,11)
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (2,0),(2,1),(2,2),(2,3),(2,4),(2,5),(2,6),(2,7),(2,8),(2,9),(2,10),(2,11)
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (3,0),(3,1),(3,2),(3,3),(3,4),(3,5),(3,6),(3,7),(3,8),(3,9),(3,10),(3,11)
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (4,0),(4,1),(4,2),(4,3),(4,4),(4,5),(4,6),(4,7),(4,8),(4,9),(4,10),(4,11)
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (5,0),(5,1),(5,2),(5,3),(5,4),(5,5),(5,6),(5,7),(5,8),(5,9),(5,10),(5,11)
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (6,0),(6,1),(6,2),(6,3),(6,4),(6,5),(6,6),(6,7),(6,8),(6,9),(6,10),(6,11)
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (7,0),(7,1),(7,2),(7,3),(7,4),(7,5),(7,6),(7,7),(7,8),(7,9),(7,10),(7,11)
	{ E, E, E, E, E, E, E, E, E, E, E, E },
	{ E, E, E, E, E, E, E, E, E, E, E, E },
	{ E, E, E, E, E, E, E, E, E, E, E, E },
	{ E, E, E, E, E, E, E, E, E, E, E, E },
	{ E, E, E, E, E, E, E, E, E, E, E, E },
	{ E, E, E, E, E, E, E, E, E, E, E, E },
	{ E, E, E, E, E, E, E, E, E, E, E, E },
	{ E, E, E, E, E, E, E, E, E, E, E, E },
	{ E, E, E, E, E, E, E, E, E, E, E, E },
	{ E, E, E, E, E, E, E, E, E, E, E, E },
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (18,0),(18,1),(18,2),(18,3),(18,4),(18,5),(18,6),(18,7),(18,8),(18,9),(18,10),(18,11)
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (19,0),(19,1),(19,2),(19,3),(19,4),(19,5),(19,6),(19,7),(19,8),(19,9),(19,10),(19,11)
	{ E, E, E, E, E, E, E, E, E, E, E, E }, // (20,0),(20,1),(20,2),(20,3),(20,4),(20,5),(20,6),(20,7),(20,8),(20,9),(20,10),(20,11)
	};

	clock_t startT, endT;
	const int INTERVAL_TIME = 300; // ms 단위

public:
	void game_init() override;

	void game_start() override;

	void game_over() override;

	void key_input(char key_code) override;

	std::string get_game_name() const override;
};

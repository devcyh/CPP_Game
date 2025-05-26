#include "Tetris.h"

void Tetris::game_init()  {
	//const char* file_path = "sample1.wav";
	//sound_play(file_path);

	// 콘솔 초기화
	// 콘솔 정보를 console 구조체에 담자
	// 콘솔 초기값으로 세팅된다.

	console_init(&console);
	set_cursor_visible(&console, false);
	//console_display_info(&console);

	//console_set_pos(&console, 32, 32); // 이게 되나? 윈도 바탕화면에서 콘솔의 위치를 결정함
	console_set_fore_color(&console, GREEN); // back_color 신경쓰기 귀찮을때, 
	//console_set_back_color(&console, RED);
	//console_set_color(&console, RED, YELLOW);
	//console_set_default_color(&console); // 콘솔 초기 칼라로 설정 white, black
	//console_set_xy(&console, 32, 32); // 커서의 x,y위치를 설정함
	//cnosole_hide_cursor(true); // 커서 감추기

	/*
		console_display_info(&console);
	;   // 기본 윈도우 콘솔값 (Default)
		//This Console information.
		//[1] Size(cols, rows) = (120, 30)
		//[2] Colors(fore, back) = (white, black)
		//[3] Cursor(x, y, hide) = 0, 0, 1)
		printf("Press Enter...");
		getchar();

		// 내가원하는 사이즈, 색상으로 변경하자.
		// 윈도우 콘솔 사이즈 변경
		console_set_size(&console, 100, 50);
		console_set_color(&console, RED, BLUE);
		console_set_cursor(&console, 11, 22, false);
		console_clear(&console);
		console_display_info(&console);
		printf("Press Enter...");
		getchar();


		console_set_size(&console, 160, 40);
		console_set_color(&console, BLACK, PURPLE);
		console_clear(&console);
		console_display_info(&console);
		printf("Press Enter...");
		getchar();


		console_set_size(&console, DEFAULT_COLS, DEFAULT_ROWS);
		console_set_color(&console, WHITE, BLACK);
		console_set_fill_color(BLACK);
		console_set_default_color(&console);
		console_display_info(&console);

		printf("Press Enter...");
		getchar();
	*/

	console_set_cursor(&console, 0, 0, false);
	console_set_fill_color(BLACK);

	//cell_draw_test(&console); // 테스트용, 지워도 무방하지만 종종 테스트 및 좌표 계산때문에 필요하다.
	// 최종 릴리즈에서 지워도 된다. 보기 불편하다면 주석처리
	//getchar();

	board_init(gboard, (int (*)[BOARD_WIDTH])board_data_attributes); // 보드 데이터로 보드를 초기화 한다.


	//block_init(&my_block, BLOCK_S); // 초기화
	//block_set_xy(&my_block, 0, 0);

	//cell_t my_cell;
	//cell_init(&my_cell, 0, 0, N, RED); // 좌표계 점검용 테스트 코드
	//board_insert_cell(gboard, &my_cell, 10, 19);
	//board_insert_cell(gboard, &my_cell, 1, 0);
	//board_insert_cell(gboard, &my_cell, 1, 19);
	//board_insert_cell(gboard, &my_cell, 10, 0);
	//cell_draw(&my_cell, 0, 0); // 좌상단

	//block_rotate(&my_block);
	//board_clear_data(gboard); // 보드를 지운다. (정확히 말하자면, 보드 데이터 내의 내용을 지운다. 화면을 지우는게 아니라.)
	////board_insert_block(gboard, &my_block, 2, 2);
	//board_draw(&console, gboard);

	//getchar();

	/*
		block_t block_I; // 테스트용으로 블럭을 7개 만들어 봤다.
		block_t block_J;
		block_t block_L;
		block_t block_O;
		block_t block_S;
		block_t block_T;
		block_t my_block;

		block_init(&block_I, BLOCK_I);
		block_init(&my_block, BLOCK_J);
		//block_init(&my_block, BLOCK_L);
		block_init(&block_O, BLOCK_O);
		block_init(&block_S, BLOCK_S);
		block_init(&block_T, BLOCK_T);
		//block_init(&my_block, BLOCK_Z);

		//block_display_info(&block_I, true);
		//block_display_info(&block_J, true);
		//block_display_info(&block_L, true);
		//block_display_info(&block_O, true);
		//block_display_info(&block_S, true);
		//block_display_info(&block_T, true);
		//block_display_info(&block_Z, true);

		block_set_xy(&my_block, 4, 4);
		block_draw(&my_block);
*/
//key_init();
}

void Tetris::game_start() {
	block_init(&my_block, BLOCK_S); // 초기화

	board_clear_data(gboard); // 보드를 지운다. (정확히 말하자면, 보드 데이터 내의 내용을 지운다. 화면을 지우는게 아니라.)
	board_insert_block(gboard, &my_block, 2, 2);
	board_draw(&console, gboard);

	startT = endT = clock();
}

void Tetris::game_over(){
	std::cout << "game_over\n";
}

void Tetris::key_input(char key_code) {
	endT = clock();
	int duration = (int)(endT - startT);

	if (duration >= INTERVAL_TIME) {
		bool ret = board_move_block(&console, gboard, &my_block, DIR_DOWN);
		if (ret == false) {
			board_change_N_to_F(gboard);

			// 부칸 확인

			// 다음 블록 소환
			block_shapes_t rand_block = (block_shapes_t)(rand() % BLOCK_MAX);

			block_init(&my_block, rand_block); // 초기화
			//block_set_xy(&my_block, 0, 0);

			//board_clear_data(gboard);
			board_insert_block(gboard, &my_block, 2, 2);
			board_draw(&console, gboard);
		}

		startT = endT;

		return;
	}

	switch (key_code) {

	case NULL:
		break;

	case KEY_UP:
		board_rotate_block(&console, gboard, &my_block);
		break;

	case KEY_DOWN:
		board_move_block(&console, gboard, &my_block, DIR_DOWN);
		break;

	case KEY_LEFT:
		board_move_block(&console, gboard, &my_block, DIR_LEFT);
		break;

	case KEY_RIGHT:
		board_move_block(&console, gboard, &my_block, DIR_RIGHT);
		break;

	case KEY_SPACE:
		//my_block.y = 
		//board_move_block(&console, gboard, &my_block, DIR_RIGHT);
		break;
	}

}

std::string Tetris::get_game_name() const {
	return "Tetris";
}
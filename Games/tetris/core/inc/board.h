#pragma once
#include "../../driver/inc/cell.h"


// ----------------------------------
// 테트리스의 표준적인 게임 필드 크기는 가로 10블록, 세로 20블록입니다.
#define BOARD_WIDTH 10 + 2 // 2가 늘어난것은 왼쪽 오른쪽 Wall Cell이다.
#define BOARD_HEIGHT 20 + 1 // 1이 늘어난것은 위와 마찬가지로 Bottom Cell

#define BOARD_START_X (4)
#define BOARD_START_Y (4)

#define DIR_UP 1
#define DIR_DOWN 2
#define DIR_LEFT 3
#define DIR_RIGHT 4

void board_init(cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH], int data[BOARD_HEIGHT][BOARD_WIDTH]);
void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_insert_block(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y);

bool board_move_block(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint8_t dir);
void board_rotate_block(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block);
void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_insert_cell(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y);
void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_change_N_to_F(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_insert_block(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y);
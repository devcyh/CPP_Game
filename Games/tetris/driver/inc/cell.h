#pragma once
#include <stdint.h>

#include "../../core/inc/point.h"
#include "../../core/inc/blocks.h"


#include "console.h"


#define DEFAULT_COLS 120
#define DEFAULT_ROWS 30

#define RESIZE_COLS (DEFAULT_COLS-30) //=90
#define RESIZE_ROWS 30

typedef struct _cell_t {
    point_t point; // cell의 위치
    color_t color; // cell의 색상
    cell_attributes_t att; // cell의 속성
} cell_t;


void cell_init(cell_t* cell, int x, int y, cell_attributes_t att, color_t color);

//void draw_one_cell(cell_t* cell, uint32_t x, uint32_t y) {
void cell_draw(cell_t* cell, uint32_t x, uint32_t y);
void cell_draw_test(windows_console_t* console);
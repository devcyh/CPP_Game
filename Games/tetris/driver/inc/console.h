#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "../../core/inc/color.h"

#include "../../model.h"


#define DEFAULT_COLS 120
#define DEFAULT_ROWS 30

#define RESIZE_COLS (DEFAULT_COLS-30) //=90
#define RESIZE_ROWS 30


void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows);
void console_clear(windows_console_t* console);
void console_set_cursor(windows_console_t* console, uint32_t x, uint32_t y, bool value);
void console_init(windows_console_t* console);
void console_display_info(const windows_console_t* console);
void console_set_fore_color(windows_console_t* console, uint8_t fore_color);
void console_set_back_color(windows_console_t* console, uint8_t back_color);
void console_set_color(windows_console_t* console, uint8_t fore_color, uint8_t back_color);
void console_set_default_color(windows_console_t* console);
void console_set_fill_color(int background_color);
//void clearPreviousPosition(int x, int y) {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD pos = { x, y };
//    DWORD written;
//    FillConsoleOutputCharacter(hConsole, ' ', 1, pos, &written); // 이전 위치를 공백으로 덮음
//}

void console_clear_region(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

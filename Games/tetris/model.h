#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "core/inc/color.h"


typedef struct _cursor_info_t {
	uint32_t x;
	uint32_t y;
	bool is_hide;
} cursor_info_t;

typedef struct _windows_console_t {
	uint32_t cols;
	uint32_t rows;

	color_t fore_color;
	color_t back_color;

	cursor_info_t cursor_info;
} windows_console_t;


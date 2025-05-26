#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <windows.h>

#include "../../core/inc/point.h"

#include "../../model.h"
// 커서의 숨김,표시 정보를 가져오는 함수
bool get_cursor_visibility(void);
void set_cursor_visible(windows_console_t* console, bool hide);
void SetCurrentCursorPos(int x, int y);
point_t GetCurrentCursorPos(void);
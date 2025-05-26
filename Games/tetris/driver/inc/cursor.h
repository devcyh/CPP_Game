#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <windows.h>

#include "../../core/inc/point.h"

#include "../../model.h"
// Ŀ���� ����,ǥ�� ������ �������� �Լ�
bool get_cursor_visibility(void);
void set_cursor_visible(windows_console_t* console, bool hide);
void SetCurrentCursorPos(int x, int y);
point_t GetCurrentCursorPos(void);
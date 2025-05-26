#include "../inc/color.h"

//�߰������� ���� ������ �ش� ���� 8�� ���� ������ ǥ���˴ϴ�(��: ���� �Ķ��� 9).
char* color_strings[16] = {
    "black", // ����
    "blue", // �Ķ�
    "green", // �ʷ�
    "cyan", // û��
    "red", // ����
    "purple", // ����
    "yellow", // ���
    "white", // ���
    "gray", // ȸ��
    "light blue", // ���� �Ķ�
    "light green", // ���� ȸ��
    "light cyan", // ���� û��
    "light red", // ���� ����
    "light purple", // ���� ����
    "light yellow", // ���� ���
    "light white" // ���� ���
};

char* get_color_string(color_t color) {
    if (color >= BLACK && color <= LIGHT_WHITE) {
        return color_strings[color]; // ��ȿ�� ���� ���̸� �ش� ���ڿ� ��ȯ
    }
    else {
        return "unknown"; // ��ȿ���� ���� ���̸� �⺻�� ��ȯ
    }
}

void setcolor(unsigned short text, unsigned short back) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
#include "tictactoe.h"

void game::TicTacToe::initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + (i * 3 + j); // ���忡 '1' ~ '9' ä���
        }
    }
    currentPlayer = 'X'; // ù ��° �÷��̾�� 'X'
    isPlaying = false;
}

// ���� ��� �Լ�
void game::TicTacToe::printBoard() const{
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|"); // �� ���м�
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n"); // �� ���м�
    }
    printf("\n");
}

// �¸� ���� Ȯ�� �Լ�
bool game::TicTacToe::checkWin() const{
    // ��� �� Ȯ��
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // �밢�� Ȯ��
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

// ���º� ���� Ȯ�� �Լ�
bool game::TicTacToe::checkDraw() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

// �÷��̾� �Է� ó�� �Լ�
bool game::TicTacToe::makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move. Try again.\n");
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

// �÷��̾� ��ȯ �Լ�
void game::TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// ���� �ʱ�ȭ �Լ�
void game::TicTacToe::game_init() {
    this->initializeBoard();
}


void game::TicTacToe::game_start() {
    printf("Welcome to Tic-Tac-Toe!\n");

    printf("Player %c, enter your move (1-9): ", currentPlayer);
    printBoard();
}

void game::TicTacToe::game_over() {
    printf("Bye\n");
}

std::string game::TicTacToe::get_game_name() const {
    return "Tic Tac Toe";
}

void game::TicTacToe::key_input(char key_code) {
    if (!key_code) return;
    int position = key_code - '0';
    if (!makeMove(position)) { 
        printf("�ٽ� �Է����ּ��� \n");
        return;
    }

    if (checkWin()) {
        printBoard();
        printf("Player %c wins!\n\n\n\n\n", currentPlayer);
        this->game_init();
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        printBoard();
        return;
    }

    if (checkDraw()) {
        printBoard();
        printf("It's a draw!\n\n\n\n\n");
        this->game_init();
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        printBoard();
        return;
    }

    switchPlayer();
    printf("Player %c, enter your move (1-9): ", currentPlayer);
    printBoard();
}
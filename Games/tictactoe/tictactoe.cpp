#include "tictactoe.h"

void game::TicTacToe::initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + (i * 3 + j); // 보드에 '1' ~ '9' 채우기
        }
    }
    currentPlayer = 'X'; // 첫 번째 플레이어는 'X'
    isPlaying = false;
}

// 보드 출력 함수
void game::TicTacToe::printBoard() const{
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|"); // 열 구분선
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n"); // 행 구분선
    }
    printf("\n");
}

// 승리 조건 확인 함수
bool game::TicTacToe::checkWin() const{
    // 행과 열 확인
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // 대각선 확인
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

// 무승부 조건 확인 함수
bool game::TicTacToe::checkDraw() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

// 플레이어 입력 처리 함수
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

// 플레이어 전환 함수
void game::TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// 보드 초기화 함수
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
        printf("다시 입력해주세요 \n");
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
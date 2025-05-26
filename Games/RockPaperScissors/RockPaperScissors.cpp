#define _CRT_SECURE_NO_WARNINGS
#include "RockPaperScissors.h"


namespace game {

    void RockPaperScissors::printChoice(int choice) const{
        if (choice == 1) printf("가위");
        else if (choice == 2) printf("바위");
        else if (choice == 3) printf("보");
    }

    int RockPaperScissors::determineWinner(int userChoice, int computerChoice) const{
        if (userChoice == computerChoice) return 0;
        if ((userChoice == 1 && computerChoice == 3) ||
            (userChoice == 2 && computerChoice == 1) ||
            (userChoice == 3 && computerChoice == 2)) return 1;
        return -1;
    }

    void RockPaperScissors::game_init() {
        srand((unsigned int)time(NULL));
    }

    void RockPaperScissors::game_start() {
        printf("\033[2J\033[H");
        printf("가위바위보 게임에 오신 것을 환영합니다!\n");
        printf("(가위,바위,보)=(1,2,3)\r\n");
        printf("당신의 선택은 ? ");
    }

    void RockPaperScissors::game_over() {
        printf("게임을 종료합니다. 감사합니다!\n");
    }

    std::string game::RockPaperScissors::get_game_name() const {
        return "Rock Paper Scissors";
    }


    void RockPaperScissors::key_input(char key_code) {
        if (!key_code) return;
        if (key_code < '1' || key_code > '3') {
            printf("잘못된 입력입니다. 1,2,3 중에서 선택하세요.\n");
            return;
        }

        userChoice = key_code - '0';
        computerChoice = rand() % 3 + 1;

        printf("\nYou : ");
        printChoice(userChoice);
        printf("\nCom : ");
        printChoice(computerChoice);

        int result = determineWinner(userChoice, computerChoice);
        if (result == 0) printf("\n결과: 비겼습니다!\n");
        else if (result == 1) printf("\n결과: 당신이 이겼습니다!\n");
        else printf("\n결과: 컴퓨터가 이겼습니다!\n");

        printf("\n\n\n");

        printf("(가위,바위,보)=(1,2,3)\r\n");
        printf("당신의 선택은 ? ");
    }

}

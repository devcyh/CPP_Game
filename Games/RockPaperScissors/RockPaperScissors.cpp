#define _CRT_SECURE_NO_WARNINGS
#include "RockPaperScissors.h"


namespace game {

    void RockPaperScissors::printChoice(int choice) const{
        if (choice == 1) printf("����");
        else if (choice == 2) printf("����");
        else if (choice == 3) printf("��");
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
        printf("���������� ���ӿ� ���� ���� ȯ���մϴ�!\n");
        printf("(����,����,��)=(1,2,3)\r\n");
        printf("����� ������ ? ");
    }

    void RockPaperScissors::game_over() {
        printf("������ �����մϴ�. �����մϴ�!\n");
    }

    std::string game::RockPaperScissors::get_game_name() const {
        return "Rock Paper Scissors";
    }


    void RockPaperScissors::key_input(char key_code) {
        if (!key_code) return;
        if (key_code < '1' || key_code > '3') {
            printf("�߸��� �Է��Դϴ�. 1,2,3 �߿��� �����ϼ���.\n");
            return;
        }

        userChoice = key_code - '0';
        computerChoice = rand() % 3 + 1;

        printf("\nYou : ");
        printChoice(userChoice);
        printf("\nCom : ");
        printChoice(computerChoice);

        int result = determineWinner(userChoice, computerChoice);
        if (result == 0) printf("\n���: �����ϴ�!\n");
        else if (result == 1) printf("\n���: ����� �̰���ϴ�!\n");
        else printf("\n���: ��ǻ�Ͱ� �̰���ϴ�!\n");

        printf("\n\n\n");

        printf("(����,����,��)=(1,2,3)\r\n");
        printf("����� ������ ? ");
    }

}

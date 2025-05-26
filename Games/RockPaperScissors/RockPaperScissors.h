#ifndef ROCK_PAPER_SCISSORS_H
#define ROCK_PAPER_SCISSORS_H

#include "../../IGame.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace game {

    class RockPaperScissors : public IGame {
    public:
        uint8_t userChoice = 0;
        uint8_t computerChoice = 0;
        uint8_t playAgain = 0;

        void game_init() override;
        void game_start() override;
        void game_over() override;
        void key_input(char key_code) override;
        std::string get_game_name() const override;

    private:
        void printChoice(int choice) const;
        int determineWinner(int userChoice, int computerChoice) const;
    };

}

#endif
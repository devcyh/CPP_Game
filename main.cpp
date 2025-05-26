#define _CRT_SECURE_NO_WARNINGS

#include "Cabinet/inc/Cabinet.h"

//add gmae header
#include "Games/RockPaperScissors/RockPaperScissors.h"
#include "Games/tictactoe/tictactoe.h"
#include "Games/Baseball/baseball.h"
#include "Games/tetris/Tetris.h"

#define Max_games 5

int main() {
	IGame* rps_games[Max_games];
	std::string title[Max_games];

	rps_games[0] = new game::RockPaperScissors();
	rps_games[1] = new game::Baseball();
	rps_games[2] = new game::TicTacToe();
	rps_games[3] = new Tetris();


	Cabinet cabinet;
	int num_games = 4;
	int index_game = 0;

	for (int i = 0; i < num_games; i++) {

		title[i] = rps_games[i]->get_game_name();
	}

	//HW check
	//cabinet.hw_check();

	while (true) {
		cabinet.choose_game(num_games, title, index_game);
		if (index_game == -1) {
			break;
		}
		cabinet.load_game(rps_games[index_game]);
		cabinet.game_init();
		cabinet.game_start();
		//cabinet.unload_game();
	}

	for (int i = 0; i < num_games; i++) {
		delete rps_games[i];
		rps_games[i] = nullptr;
	}

	return 0;
}
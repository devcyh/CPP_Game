#ifndef __IGAME_H__
#define __IGAME_H__

#include <string>

class IGame {
public:
	virtual ~IGame() = default;
	virtual void game_init() = 0;
	virtual void game_start() = 0;
	virtual void game_over() = 0;
	virtual void key_input(char key_code) = 0;
	virtual std::string get_game_name() const = 0;
};

#endif // !__IGAME_H__
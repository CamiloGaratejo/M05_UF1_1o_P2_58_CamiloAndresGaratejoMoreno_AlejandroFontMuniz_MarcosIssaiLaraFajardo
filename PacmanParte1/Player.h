#include "ConsoleUtils.h"
#include "Map.h"
//#include "enemy.h"
#include <vector>

enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
class Player
{

private:
	COORD spawn;
	COORD direction;
	char character = 'A';
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::DARK_RED;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;
public:
	COORD position;
	int points = 0;
	Player(COORD _spawn);
	void update(Map* _map, USER_INPUTS input/*, std::vector<enemy>* enemies*/);
	void draw();
};

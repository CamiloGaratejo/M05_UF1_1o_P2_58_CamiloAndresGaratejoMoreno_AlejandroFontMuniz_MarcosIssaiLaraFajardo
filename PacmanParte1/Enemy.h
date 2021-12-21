#pragma once
#include "ConsoleUtils.h";
#include "TimeManager.h"
#include "Map.h";
#include <stdlib.h>
#include <time.h>
class Enemy
{
private:
	COORD spawn;
	COORD position;
	COORD direction;
	char character = 'W';
	float powerup_countdwn = 0;
	const float powerup_countdwn_time = 15;
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::DARK_RED;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;

	ConsoleUtils::CONSOLE_COLOR foreground_powerUp = ConsoleUtils::CONSOLE_COLOR::DARK_RED;
	ConsoleUtils::CONSOLE_COLOR foreground_attack = ConsoleUtils::CONSOLE_COLOR::CYAN;
	void RamdomDirection();
public:
	enum  ENEMY_STATE { ENEMY_NONE, ENEMY_KILLED, ENEMY_DEAD };
	Enemy();
	Enemy(COORD _spawn);
	void Draw();
	void PowerUpPicked();
	ENEMY_STATE Update(Map* _mapa, COORD _player);
};


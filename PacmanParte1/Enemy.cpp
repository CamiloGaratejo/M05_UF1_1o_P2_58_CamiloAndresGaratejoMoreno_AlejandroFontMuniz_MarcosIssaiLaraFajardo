#include "Enemy.h"

void Enemy::RamdomDirection()
{
	direction = { 0,0 };
	int ramdom = rand() % 4;
	switch (ramdom)
	{
	case 0:
		direction.X = 1;
		break;
	case 1:
		direction.X = -1;
		break;
	case 2:
		direction.Y = 1;
		break;
	case 3:
		direction.Y = -1;
		break;
	default:
		break;
	}
}

Enemy::Enemy()
{
	spawn = { 0,0 };
	position = { 0,0 };
	direction = { 0,0 };

}
Enemy::Enemy(COORD _spawn)
{
	spawn = _spawn;
	position = _spawn;
	direction = { 0,0 };
}
void Enemy::Draw()
{
	ConsoleUtils::Console_SetPos(position);
	ConsoleUtils::Console_SetColor(foreground, background);
	std::cout << character;
}

void Enemy::PowerUpPicked()
{
	powerup_countdwn = TimeManager::getInstance().time + powerup_countdwn_time;
}


Enemy::ENEMY_STATE Enemy::Update(Map* _mapa, COORD _player)
{

	RamdomDirection();
	COORD newPosition = position;
	newPosition.X += direction.X;
	newPosition.Y += direction.Y;
	if (newPosition.X < 0)
	{
		newPosition.X = _mapa->Width - 1;
	}
	newPosition.X %= _mapa->Width;
	if (newPosition.Y < 0)
	{
		newPosition.Y = _mapa->Height - 1;
	}
	switch (_mapa->GetTile(newPosition.X, newPosition.Y))
	{
	case Map::MAP_TILES::MAP_WALL:
		newPosition = position;
		break;
	}
	position = newPosition;

	ENEMY_STATE state = ENEMY_STATE::ENEMY_NONE;
	if (position.X == _player.X && position.Y == _player.Y) {
		if (powerup_countdwn <= TimeManager::getInstance().time) {
			state = ENEMY_STATE::ENEMY_DEAD;
		}
		else {
			position = spawn;
			state = ENEMY_STATE::ENEMY_KILLED;
		}
	}
	if (powerup_countdwn <= TimeManager::getInstance().time) {
		foreground = foreground_attack;
	}
	else {
		foreground = foreground_powerUp;
	}
	return state;
}

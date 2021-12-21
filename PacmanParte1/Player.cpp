#include "Player.h"

Player::Player(COORD _spawn)
{
    spawn = _spawn;
    position = _spawn;
    direction = { 5, 4 };
}

void Player::update(Map* _map, USER_INPUTS input, std::vector<Enemy>* Enemys)
{
    COORD newPosition = position;

    switch (input)
    {
    case UP:
        newPosition.Y--;
        break;
    case DOWN:
        newPosition.Y++;
        break;
    case RIGHT:
        newPosition.X++;
        break;
    case LEFT:
        newPosition.X--;
        break;
    }
    if (newPosition.X < 0)
    {
        newPosition.X = _map->Width - 1;
    }
    newPosition.X %= _map->Width;
    if (newPosition.Y < 0)
    {
        newPosition.Y = _map->Height - 1;
    }
    newPosition.Y %= _map->Height;

    switch (_map->GetTile(newPosition.X, newPosition.Y))
    {
    case Map::MAP_TILES::MAP_WALL:

        newPosition.Y = position.Y;
        newPosition.X = position.X;
        break;
    case Map::MAP_TILES::MAP_POINT:
        _map->points--;
        points++;
        _map->SetTile(newPosition.X, newPosition.Y, Map::MAP_TILES::MAP_EMPTY);
        break;
    case Map::MAP_TILES::MAP_POWERUP:
        points += 25;
        for (size_t i = 0; i < Enemys->size(); i++)
        {
            Enemys->at(i).PowerUpPicked();


        }
        _map->SetTile(newPosition.X, newPosition.Y, Map::MAP_TILES::MAP_EMPTY);
        break;
    }

    position = newPosition;
}

void Player::draw()
{
    ConsoleUtils::Console_SetPos(position);
    ConsoleUtils::Console_SetColor(foreground, background);
    std::cout << character;
}

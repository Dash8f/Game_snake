#pragma once

#include <string>
#include <iostream>

#include "../Game/game.hpp"

class Controller
{
public:
    Game& game;

public:
Controller(Game& game_) : game(game_)
{
}
std::string get_user_input() const;
};


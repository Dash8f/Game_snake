#pragma once

#include <string>
#include <iostream>

#include <stdint.h>

#include "../Ui/view.hpp"


class Game
{
public:
class Snake
{
public:
    std::vector<std::pair<int, int>> coordinates;

    size_t lenght;

public:
    Snake();
    ~Snake() = default;

    void move_head(int new_x, int new_y);

    void increase_snake();

    std::pair<int, int> get_head_coord();
};

class Rabbit
{

};

public:
Snake snake;

private:
UI& ui;

public:
Game(UI& ui_);
~Game() {};
};


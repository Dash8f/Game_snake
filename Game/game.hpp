#pragma once

#include <string>
#include <iostream>

#include <stdint.h>

#include "../Ui/view.hpp"


class Game
{
private:
UI& ui;

public:
Game(UI& ui_) : ui(ui_) {};
~Game() {};

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
};


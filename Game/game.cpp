#include<iostream>

#include"game.hpp"
#include"../Ui/view.hpp"

Game::Snake::Snake()
{
    lenght = 1;

    coordinates.push_back({0, 0});
}

void Game::Snake::move_head(int new_x, int new_y)
{
    /*if(fruit case)
    {
        increase_snake();
    }*/

    for(size_t i = 1; i < lenght; ++i)
    {
        coordinates[i].first  = coordinates[i-1].first;
        coordinates[i].second = coordinates[i-1].second;
    }

    coordinates[0] = {new_x, new_y};
}

void Game::Snake::increase_snake()
{
    coordinates.push_back({0, 0});

}

std::pair<int, int> Game::Snake::get_head_coord()
{
    return coordinates[0];
}

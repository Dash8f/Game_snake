#include "controller.hpp"

std::string Controller::get_user_input() const
{
    std::string tmp;

    std::cin >> tmp;

    return tmp;
}

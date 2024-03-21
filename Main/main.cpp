#include <string.h>

#include "../Controller/controller.hpp"
#include "../Ui/view.hpp"
#include "../Game/game.hpp"

#include <memory>

int main()
{
   // std::cout << "\e[H\e[J" << std::flush;

    UI* ui = UI::get(text_mode);
    Game       game(*ui);
    Controller controller(game);

    ui->draw();

    while(1)
    {

    };

    return 0;
}

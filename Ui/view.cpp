#include "view.hpp"
#include <iostream>
#include <stdio.h>

#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>


UI* UI::ui;

UI* UI::get(UIMode mode)
{
    if (ui) 
    {
        return ui;
    }

    if (mode == text_mode)
    {
        ui = new TextUI;

        return ui; 
    }

    ui = new GraphUI;

    return ui;
};

UI::UI() {};
UI::~UI() {};

void UI::draw() {};

TextUI::TextUI() 
{
    winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    width = w.ws_col;
    height = w.ws_row;

    termios attributes;
    tcgetattr(STDIN_FILENO, &attributes);

    saved_attributes = attributes;

    attributes.c_lflag &= ~ECHO;
    attributes.c_lflag &= ~ICANON;

    tcsetattr(STDIN_FILENO, TCSANOW, &attributes);
    std::cout << 'aaa' << std::endl;
};

TextUI::~TextUI() 
{
    tcsetattr(STDIN_FILENO, TCSANOW, &saved_attributes);
    std::cout << 'bbb' << std::endl;
};

void TextUI::draw()
{
        clear_screen();
        set_color(blue);

        //draw

        set_color(white);

};

void TextUI::clear_screen() const
{
    std::cout << "\e[H\e[J" << std::flush;
};

void TextUI::set_color(Color color_) const
{
    std::cout << "\x1b[" << color_ << "m" << std::flush;
    std::cout << std::flush;
};

GraphUI::GraphUI() {};
GraphUI::~GraphUI() {};

void GraphUI::draw() {};

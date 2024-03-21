#include "view.hpp"
#include <iostream>
#include <stdio.h>

#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>


void SetCursorPos(int XPos, int YPos)
{
 printf("\033[%d;%dH", YPos+1, XPos+1);
}


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
    std::vector<std::pair<int, int>> coords = {
    {1, 2},
    {1, 3},
    {1, 4}
}; 

    clear_screen();
    draw_frame(green_);
    draw_snake(coords, red_);
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

void TextUI::draw_line(char left_char, char mid_char, char right_char)
{
    std::cout << left_char;

    for(uint16_t x = 0; x != width - 2; ++x)
    {
        std::cout << mid_char;
    }

    std::cout << right_char << std::flush;
}

void TextUI::draw_frame(Color color_)
{
    set_color(color_);
    draw_line('@', '@', '@');

    for(int cnt = 0; cnt != height - 2; ++cnt)
        draw_line('@', ' ', '@');

    draw_line('@', '@', '@');

    set_color(white_);
}

void TextUI::draw_in_coords(int x_coord, int y_coord, char symbol, Color color_)
{
    set_color(color_);

    SetCursorPos(x_coord, y_coord);
    std::cout << symbol;

    set_color(white_);
}

void TextUI::draw_snake(std::vector<std::pair<int, int>> coords_, Color color_)
{
    uint16_t len = coords_.size();

    for(uint16_t cnt = 0; cnt < len; ++cnt)
    {
        draw_in_coords(coords_[cnt].first, coords_[cnt].second, '#', red_);
    }
}

GraphUI::GraphUI() {};
GraphUI::~GraphUI() {};

void GraphUI::draw() {};
void GraphUI::draw_frame() {};

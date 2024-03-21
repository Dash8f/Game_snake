#pragma once

#include <sys/ioctl.h>
#include <string>
#include <termios.h>
#include <stdint.h>

enum Color
{
    black_      =   30,
    red_        =   31,
    green_      =   32,
    blue_       =   34,
    yellow_     =   33,
    magenta_    =   35,
    cyan_       =   36,
    white_      =   37,
    normal      =   0,
    bright      =   1,
    dim         =   2,
    underscore  =   4,
    blink       =   5,
    reverse     =   7,
    hidden      =   8,
    black       =   40,
    red         =   41,
    green       =   42,
    yellow      =   43,
    blue        =   44,
    magenta     =   45,
    cyan        =   46,
    white       =   47
};

enum UIMode
{
    text_mode,
    graph_mode
};

class UI
{
private:
std::string game_name = "SNAKE";

public:
static UI* ui;

public:
UI();
virtual ~UI();

virtual void draw() = 0;
//virtual void draw_snake() = 0;

static UI* get(UIMode mode = text_mode);
};

class TextUI : public UI
{
public:
uint16_t width;
uint16_t height;

termios saved_attributes;

public:
TextUI();
virtual ~TextUI();

virtual void draw();

private:
void clear_screen() const;

void set_color(Color color_) const;

void draw_line(char left_char, char mid_char, char right_char);
void draw_frame(Color color_);
void draw_in_coords(int x_coord, int y_coord, char symbol, Color color_);
void draw_snake(std::vector<std::pair<int, int>> coords_, Color color_);
};

class GraphUI : public UI
{
public:
GraphUI();
virtual ~GraphUI();

virtual void draw();

private:
void draw_frame();
};
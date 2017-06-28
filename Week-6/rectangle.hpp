#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "hwlib.hpp"

class rectangle
{
private:
    hwlib::glcd_oled& display;

public:
    rectangle(hwlib::glcd_oled& display);

    void draw_rectangle(int start_x, int start_y, int size);
};

#endif // RECTANGLE_HPP

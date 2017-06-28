#ifndef LINE_HPP
#define LINE_HPP

#include "hwlib.hpp"

class line
{
private:
    hwlib::glcd_oled& display;

public:
    line(hwlib::glcd_oled& display);

    void draw_line(int start_x, int start_y, const int end_x, const int end_y);
};

#endif // LINE_HPP

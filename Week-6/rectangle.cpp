#include "rectangle.hpp"
#include "line.hpp"

rectangle::rectangle(hwlib::glcd_oled& display)
    : display(display)
{
}

void rectangle::draw_rectangle(int start_x, int start_y, int size)
{
    line line_ob(display);
    line_ob.line::draw_line(start_x, start_y, (start_x + size), start_y);
    line_ob.line::draw_line((start_x + size), start_y, (start_x + size), (start_y + size));
    line_ob.line::draw_line(start_x, start_y, start_x, (start_y + size));
    line_ob.line::draw_line(start_x, (start_y + size), (start_x + size), (start_y + size));
}

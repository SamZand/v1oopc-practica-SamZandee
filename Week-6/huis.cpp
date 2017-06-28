#include "hwlib.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "huis.hpp"

huis::huis(hwlib::glcd_oled& display)
    : display(display)
{
}

void huis::draw_huis()
{
    line line_ob(display);
    rectangle rec_ob(display);

    display.clear();
    line_ob.line::draw_line(61, 20, 75, 35);
    line_ob.line::draw_line(61, 20, 46, 35);
    line_ob.line::draw_line(65, 15, 65, 23);

    rec_ob.rectangle::draw_rectangle(50, 30, 21);
    rec_ob.rectangle::draw_rectangle(57, 44, 7);
}

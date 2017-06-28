#ifndef HUIS_HPP
#define HUIS_HPP

#include "hwlib.hpp"

class huis
{
private:
    hwlib::glcd_oled& display;

public:
    huis(hwlib::glcd_oled& display);

    void draw_huis();
};

#endif // HUIS_H

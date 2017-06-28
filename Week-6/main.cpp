#include "hwlib.hpp"
#include "huis.hpp"

int main(void)
{
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;

    namespace target = hwlib::target;

    auto scl = target::pin_oc(target::pins::scl);
    auto sda = target::pin_oc(target::pins::sda);

    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);

    auto display = hwlib::glcd_oled(i2c_bus, 0x3c);

    huis ob(display);

    ob.huis::draw_huis();
}

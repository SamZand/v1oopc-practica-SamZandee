#include "hwlib.hpp"

class pin_in_AND : public hwlib::pin_in
{
private:
    hwlib::pin_in& sw0;
    hwlib::pin_in& sw1;

public:
    pin_in_AND(hwlib::pin_in& sw0, hwlib::pin_in& sw1)
        : sw0(sw0)
        , sw1(sw1)
    {
    }

    bool get(hwlib::buffering buf = hwlib::buffering::unbuffered) override
    {

        return (!sw0.get() && !sw1.get());
    }
};

int main(void)
{

    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;

    namespace target = hwlib::target;

    auto ds = target::pin_out(target::pins::d8);
    auto shcp = target::pin_out(target::pins::d9);
    auto stcp = target::pin_out(target::pins::d10);
    auto spi = hwlib::spi_bus_bit_banged_sclk_mosi_miso(stcp, ds, hwlib::pin_in_dummy);
    auto hc595 = hwlib::hc595(spi, shcp);

    auto sw0 = target::pin_in(target::pins::d7);
    auto sw1 = target::pin_in(target::pins::d6);
    auto led0 = target::pin_out(target::pins::d2);
    auto led1 = target::pin_out(target::pins::d3);
    auto led2 = target::pin_out(target::pins::d4);
    auto led3 = target::pin_out(target::pins::d5);

    auto leds = hwlib::port_out_from_pins(led0, led1, led2, led3, hc595.p0, hc595.p1, hc595.p2, hc595.p3);

    auto ob = pin_in_AND(sw0, sw1);

    while(1) {
        hwlib::cout << ob.get();
    }
}

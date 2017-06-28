#include "hwlib.hpp"

void opdrachtInput(hwlib::target::pin_in sw0, hwlib::target::pin_in sw1, hwlib::port_out& leds)
{
    unsigned char count = 1;
    unsigned char max = 0b1111;
    unsigned char min = 1;

    while(1) {
        if(count > max) {
            count = max;
        } else if(count < min) {
            count = min;
        }
        hwlib::wait_ms(100);
        if(!sw0.get())
            count = (count << 1) + 1;
        if(!sw1.get())
            count = (count >> 1);
        leds.set(count);
    }
}

int main(void)
{
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;

    auto sw0 = target::pin_in(target::pins::d7);
    auto sw1 = target::pin_in(target::pins::d6);
    auto led0 = hwlib::target::pin_out(hwlib::target::pins::d5);
    auto led1 = hwlib::target::pin_out(hwlib::target::pins::d4);
    auto led2 = hwlib::target::pin_out(hwlib::target::pins::d3);
    auto led3 = hwlib::target::pin_out(hwlib::target::pins::d2);

    auto leds = hwlib::port_out_from_pins(led0, led1, led2, led3);
    ::opdrachtInput(sw0, sw1, leds);
}
//        for(;;) {
//            led0.set(1);
//            led1.set(1);
//            led2.set(0);
//            led3.set(0);
//            hwlib::wait_ms(128);
//            led0.set(0);
//            led1.set(1);
//            led2.set(1);
//            led3.set(0);
//            hwlib::wait_ms(128);
//            led0.set(0);
//            led1.set(0);
//            led2.set(1);
//            led3.set(1);
//            hwlib::wait_ms(128);
//            led0.set(0);
//            led1.set(1);
//            led2.set(1);
//            led3.set(0);
//            hwlib::wait_ms(128);
//
//        }

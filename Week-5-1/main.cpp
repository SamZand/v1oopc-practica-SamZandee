#include "hwlib.hpp"

class pin_out_invert : public hwlib::pin_out
{
private:
    hwlib::pin_out& led;

public:
    pin_out_invert(hwlib::pin_out& led)
        : led(led)
    {
    }

    void set(bool x, hwlib::buffering buf = hwlib::buffering::unbuffered) override
    {
        led.set(!x);
    }
};

class pin_out_all : public hwlib::pin_out {
private:
   hwlib::pin_out * list[ 4 ];     
   
public:

   pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy 
   ):
      list{ &p0, &p1, &p2, &p3 }
   {}
   
   void set( bool v, hwlib::buffering buf = hwlib::buffering::unbuffered){
      for( auto p  : list ){
          p->set( v );
      }
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
    
    auto leds_1 = pin_out_all(led0, led1, led2, led3);
    auto leds_2 = pin_out_all(hc595.p0, hc595.p1, hc595.p2, hc595.p3);
    auto leds_not = pin_out_invert(leds_2);
    auto leds = pin_out_all(leds_1, leds_not);
    
    hwlib::blink(leds);
    
    

}
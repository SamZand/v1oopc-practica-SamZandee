#ifndef RECHTHOEK_HPP
#define RECHTHOEK_HPP

#include "window.hpp"

class rechthoek {
private:
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
   window & w;
public:
   rechthoek( window & w, int start_x, int start_y, int end_x, int end_y ):
      start_x( start_x ),
      start_y( start_y ),
      end_x( end_x ),
      end_y( end_y ),
      w( w )
   {}
   void print();
};

#endif // RECHTHOEK_HPP
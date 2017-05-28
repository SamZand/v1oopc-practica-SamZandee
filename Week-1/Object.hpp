#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "window.hpp"

class Object {
private:
   int richting;
   window & w;
public:
   Object( window & w, int richting ):
      richting ( richting ),
      w( w )
   {}
   void print();
};

#endif // OBJECT_HPP
#include <iostream>
#include "window.hpp"
#include "Object.hpp"

int main(int argc, char **argv){
   window w( 128, 64, 10 );
   
   Object all( w, 1);
   all.print();
   
   Object all1( w, 2);
   all1.print();


   return 0;
}

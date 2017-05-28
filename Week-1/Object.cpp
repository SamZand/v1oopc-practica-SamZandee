#include <iostream>
#include "Object.hpp"
#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "rechthoek.hpp"

void Object::print(){
    if (richting == 1){ 
   
   circle ball( w, 15, 5, 1 );
   ball.print();
   
   circle ball2( w, 13, 2, 1 );
   ball2.print();
   
   line dak1( w, 9, 20, 26, 5 );
   dak1.print();
   
   line dak2( w, 41, 20, 24, 5 );
   dak2.print();
   
   rectangle huis( w, 10, 20, 40, 50 );
   huis.print();
   
   rectangle deur( w, 30, 40, 35, 50 );
   deur.print();
      
   rechthoek schoorsteen(w, 8, 15, 15, 17);
    schoorsteen.print();}
    
    if (richting == 2){
    
    circle ball( w, 95, 5, 1 );
   ball.print();
   
   circle ball2( w, 97, 2, 1 );
   ball2.print();
   
   line dak1( w, 69, 20, 86, 5 );
   dak1.print();
   
   line dak2( w, 101, 20, 84, 5 );
   dak2.print();
   
   rectangle huis( w, 70, 20, 100, 50 );
   huis.print();
   
   rectangle deur( w, 75, 40, 80, 50 );
   deur.print();
      
   rechthoek schoorsteen(w, 8, 94, 15, 96);
    schoorsteen.print();
    }

}

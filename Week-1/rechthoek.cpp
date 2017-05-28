#include "rechthoek.hpp"
#include "window.hpp"

void rechthoek::print(){
    int p_end_x = end_x;
    int p_end_y = end_y;
    
    for(int i = start_x; i < p_end_x; ++i){
        for(int j = start_y; j < p_end_y; ++j){
            w.draw(j,i);
        }
    }
}
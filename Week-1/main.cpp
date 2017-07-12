#include <iostream>
#include "window.hpp"
#include "Object.hpp"

int main(int argc, char** argv)
{
    window w(128, 64, 10);

    Object p1(w, 2, 4, 1);
    p1.print();
//    Object p2(w, 2, 20, 2);
//   p2.print();

    return 0;
}

#include <iostream>
#include "window.hpp"
#include "Object.hpp"

int main(int argc, char** argv)
{
    window w(128, 64, 10);

    Object p1(w, 1, 1, 1);
    p1.print();
    Object p2(w, 40, 1, 1.1);
    p2.print();

    return 0;
}

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "rechthoek.hpp"

/**
 * @class Object
 * @author Sam
 * @date 12/07/17
 * @file Object.hpp
 * @brief Printable house
 */

class Object
{
private:
    int x;
    int y;
    window& w;

    rechthoek recht;
    rectangle rec1;
    circle circ1, circ2;
    line lin1, lin2;

public:
    /**
             * @brief Constructs a line
             * @param Window to draw on
             * @param X Position
             * @param Y position
             * @param Scale
             */
    Object(window& w, int x, int y, float s)
        : x(x)
        , y(y)
        , w(w)
        , circ1(w, x + 15 * s, y + 5 * s, 1 * s)
        , circ2(w, x + 13 * s, y + 0 * s, 1 * s)
        , lin1(w, x + 9 * s, y + 20 * s, x + 26 * s, y + 5 * s)
        , lin2(w, x + 41 * s, y + 20 * s, x + 24 * s, y + 5 * s)
        , rec1(w, x + 10 * s, y + 20 * s, x + 40 * s, y + 50 * s)
        , recht(w, x + 30, 40 * s + y, 35 * s + x, 50 * s + y)
    {
    }
    /**
        * @brief Draws house using window::draw(x, y)
        */
    void print();
};

#endif // OBJECT_HPP
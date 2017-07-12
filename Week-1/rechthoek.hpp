#ifndef RECHTHOEK_HPP
#define RECHTHOEK_HPP

#include "window.hpp"

/**
 * @class rechthoek
 * @author Sam
 * @date 12-07-2017
 * @file rechthoek.hpp
 * @brief Printable filled rectangle
 */
class rechthoek {
	private:
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	window& w;

public:
	/**
	 * @brief Constructs a filled rectangle
	 * @param Window to draw on
	 * @param X Start Position
	 * @param Y Start Position
	 * @param X End Position
	 * @param Y End Position
	 */
	rechthoek(window& w, int start_x, int start_y, int end_x, int end_y)
	  : start_x(start_x), start_y(start_y), end_x(end_x), end_y(end_y), w(w) {}

	/**
	* @brief Draws the filled rectangle using window::draw(x, y)
	*/
	void print();
};

#endif
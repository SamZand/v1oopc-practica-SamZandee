#include "rechthoek.hpp"

void rechthoek::print() {
	for (int x = start_x; x < end_x; x++) {
		for (int y = start_y; y < end_y; y++) {
			w.draw(x, y);
		}
	}
}
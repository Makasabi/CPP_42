#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed w11 = ((a.getX()*(c.getY() - a.getY())) + ((point.getY() - a.getY()) *(c.getX()-a.getX())) - (point.getX()*(c.getY()-a.getY())));
	Fixed w12 = (((b.getY()-a.getY())*(c.getX()-a.getX()))-((b.getX()-a.getX())*(c.getY()-a.getY())));
	Fixed w1 = w11 / w12;

	Fixed w21 = point.getY() - a.getY() - w1 * (b.getY() - a.getY());
	Fixed w22 = c.getY() - a.getY();
	Fixed w2 = w21 / w22;

	if (w1 > 0 && w2 > 0 && (w1 + w2) < 1)
		return true;
	return false; 
}
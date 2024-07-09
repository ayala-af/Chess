#include"Coordinate.h"

bool operator==(const Coordinate& c1, const Coordinate& c2)
{
	return c1.getX() == c2.getX() && c1.getY() == c2.getY();
}

bool operator!=(const Coordinate& c1, const Coordinate& c2)
{
	return !(c1 == c2);
}

Coordinate operator+(const Coordinate& c1, const Coordinate& c2)
{
	return Coordinate(c1.getX() + c2.getX(), c1.getY() + c2.getY());
}

int Coordinate::getX() const {
	return m_x;
}

int Coordinate::getY() const {
	return m_y;
}

void Coordinate::setX(int x)
{
	m_x = x;
}

void Coordinate::setY(int y) {
	m_y = y;
}

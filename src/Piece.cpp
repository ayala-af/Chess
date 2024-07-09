#include"Piece.h"

const bool Piece::isWhite() const
{
	return m_is_white;
}

const bool Piece::isBlack() const
{
	return !m_is_white;
}

const char Piece::getName() const
{
	return m_name;
}

Coordinate Piece::getCoordinate() const
{
	return m_coordinate;
}

void Piece::setCoordinate(const Coordinate& new_coordinate)
{
	m_coordinate = new_coordinate;
}

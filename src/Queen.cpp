#include"Queen.h"

Queen::Queen(Coordinate coordinate, bool is_white) :Piece('q', coordinate, is_white) {}

std::vector<Coordinate> Queen::allLegalMoves(const Board& board) const
{
	std::vector<Coordinate> moves;

	Coordinate current_coordinate = this->getCoordinate();

	// check moves in diagonal directions
	// Diagonal to the upper-right
	for (int i = current_coordinate.getX() + 1, j = current_coordinate.getY() + 1; i < board._SIZE && j < board._SIZE; ++i, ++j)
	{
		Coordinate new_coordinate(i, j);
		if (board.canContain(new_coordinate, this->isWhite()))
		{
			moves.push_back(new_coordinate);
			if (board.getPiece(new_coordinate))
				break;
		}
		else
			break;
	}
	// Diagonal to the upper-left
	for (int i = current_coordinate.getX() - 1, j = current_coordinate.getY() + 1; i >= 0 && j < board._SIZE; --i, ++j)
	{
		Coordinate new_coordinate(i, j);
		if (board.canContain(new_coordinate, this->isWhite()))
		{
			moves.push_back(new_coordinate);
			if (board.getPiece(new_coordinate))
				break;
		}
		else
			break;
	}
	// Diagonal to the lower-left
	for (int i = current_coordinate.getX() - 1, j = current_coordinate.getY() - 1; i >= 0 && j >= 0; --i, --j)
	{
		Coordinate new_coordinate(i, j);
		if (board.canContain(new_coordinate, this->isWhite()))
		{
			moves.push_back(new_coordinate);
			if (board.getPiece(new_coordinate))
				break;
		}
		else
			break;
	}
	// Diagonal to the lower-right
	for (int i = current_coordinate.getX() + 1, j = current_coordinate.getY() - 1; i < board._SIZE && j >= 0; ++i, --j)
	{
		Coordinate new_coordinate(i, j);
		if (board.canContain(new_coordinate, this->isWhite()))
		{
			moves.push_back(new_coordinate);
			if (board.getPiece(new_coordinate))
				break;
		}
		else
			break;
	}
	// Check moves in vertical direction
  // Vertically upwards
	for (int i = current_coordinate.getX() + 1; i < board._SIZE; ++i)
	{
		Coordinate new_coordinate(i, current_coordinate.getY());
		if (board.canContain(new_coordinate, this->isWhite()))
		{
			moves.push_back(new_coordinate);
			if (board.getPiece(new_coordinate))
				break; // stop checking this direction if there's a piece blocking the way
		}
		else
			break; // stop checking this direction if an invalid move is detected
	}
	// Vertically downwards
	for (int i = current_coordinate.getX() - 1; i >= 0; --i)
	{
		Coordinate new_coordinate(i, current_coordinate.getY());
		if (board.canContain(new_coordinate, this->isWhite()))
		{
			moves.push_back(new_coordinate);
			if (board.getPiece(new_coordinate))
				break;
		}
		else
			break;
	}

	// Check moves in horizontal direction
	// Horizontally rightwards 
	for (int j = current_coordinate.getY() + 1; j < board._SIZE; ++j)
	{
		Coordinate new_coordinate(current_coordinate.getX(), j);
		if (board.canContain(new_coordinate, this->isWhite()))
		{
			moves.push_back(new_coordinate);
			if (board.getPiece(new_coordinate))
				break;
		}
		else
			break;
	}
	// Horizontally leftwards 
	for (int j = current_coordinate.getY() - 1; j >= 0; --j)
	{
		Coordinate new_coordinate(current_coordinate.getX(), j);
		if (board.canContain(new_coordinate, this->isWhite()))
		{
			moves.push_back(new_coordinate);
			if (board.getPiece(new_coordinate))
				break;
		}
		else
			break;
	}

	return moves;
}
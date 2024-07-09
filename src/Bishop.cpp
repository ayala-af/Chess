#include"Bishop.h"

Bishop::Bishop(Coordinate coordinate, bool is_white) :Piece('b', coordinate, is_white) {}

std::vector<Coordinate> Bishop::allLegalMoves(const Board& board) const
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

	return moves;
}


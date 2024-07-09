#include"Pawn.h"

Pawn::Pawn(Coordinate coordinate, bool is_white) :Piece('p', coordinate, is_white) {}

std::vector<Coordinate> Pawn::allLegalMoves(const Board& board) const
{
	std::vector<Coordinate> moves;
	Coordinate current_coordinate = getCoordinate();
	int direction = isWhite() ? 1 : -1;
	int starting_point = isWhite() ? 1 : 6;

	if (!WHITE_GOING_UP)
	{
		direction = isWhite() ? -1 : 1;
		starting_point = isWhite() ? 6 : 1;
	}

	// Check the square in front of the pawn
	Coordinate front_pos(current_coordinate.getX() + direction, current_coordinate.getY());
	if (board.canContain(front_pos, isWhite()) && !board.getPiece(front_pos))
	{
		moves.push_back(front_pos);

		// If the pawn is in its starting position, it can move two squares ahead
		Coordinate two_squares_front(current_coordinate.getX() + 2 * direction, current_coordinate.getY());
		if (board.canContain(two_squares_front, isWhite()) && !board.getPiece(two_squares_front) && !board.getPiece(front_pos) &&
			(current_coordinate.getX() == starting_point))
		{
			moves.push_back(two_squares_front);
		}
	}

	// Check if the pawn can capture diagonally to the left
	Coordinate left_diagonal(current_coordinate.getX() + direction, current_coordinate.getY() - 1);
	if (board.canContain(left_diagonal, isWhite()) && board.getPiece(left_diagonal) &&
		board.getPiece(left_diagonal)->isWhite() != isWhite())
	{
		moves.push_back(left_diagonal);
	}

	// Check if the pawn can capture diagonally to the right
	Coordinate right_diagonal(current_coordinate.getX() + direction, current_coordinate.getY() + 1);
	if (board.canContain(right_diagonal, isWhite()) && board.getPiece(right_diagonal) &&
		board.getPiece(right_diagonal)->isWhite() != isWhite())
	{
		moves.push_back(right_diagonal);
	}

	return moves;
}

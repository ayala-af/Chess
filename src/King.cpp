#include "King.h"

King::King(Coordinate coordinate, bool is_white) :Piece('k', coordinate, is_white) {}

std::vector<Coordinate> King::allLegalMoves(const Board& board) const
{
	std::vector<Coordinate> moves;
	Coordinate current_coordinate = getCoordinate();

	// Check all positions around the king
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i == 0 && j == 0)
				continue; // Skip the current position

			Coordinate new_coordinate = current_coordinate + Coordinate(i, j);
			if (board.canContain(new_coordinate, isWhite()))
			{
				moves.push_back(new_coordinate);
			}
		}
	}
	// Optional add check for castling on the king's side
	return moves;
}
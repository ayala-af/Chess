#pragma once
#include "Rook.h"
#include "Bishop.h"

/// <summary>
/// Represents the Queen chess piece.
/// </summary>
class Queen : public Piece
{
public:
	/// <summary>
	/// Constructs a Queen object with the given coordinate and color.
	/// </summary>
	/// <param name="coordinate">The coordinate of the Queen.</param>
	/// <param name="is_white">Indicates whether the Queen is white or black.</param>
	Queen(Coordinate coordinate, bool is_white);

	/// <summary>
	/// Calculates all legal moves for the Queen on the given board.
	/// </summary>
	/// <param name="board">The chess board.</param>
	/// <returns>A vector of coordinates representing legal moves.</returns>
	std::vector<Coordinate> allLegalMoves(const Board& board) const override;
};
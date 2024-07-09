#pragma once
#include "Piece.h"

/// <summary>
/// Represents the King chess piece.
/// </summary>
class King : public Piece
{
public:
	/// <summary>
	/// Constructs a King object with the given coordinate and color.
	/// </summary>
	/// <param name="coordinate">The coordinate of the King.</param>
	/// <param name="is_white">True if the King is white, false if black.</param>
	King(Coordinate coordinate, bool is_white);

	/// <summary>
	/// Gets all the legal moves for the King on the given board.
	/// </summary>
	/// <param name="board">The chess board.</param>
	/// <returns>A vector of Coordinate objects representing the legal moves.</returns>
	std::vector<Coordinate> allLegalMoves(const Board& board) const override;
};
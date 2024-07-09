#pragma once
#include "Piece.h"
/// <summary>
/// Represents the Knight chess piece.
/// </summary>
class Knight : public Piece
{
public:
	/// <summary>
	/// Constructs a Knight object with the given coordinate and color.
	/// </summary>
	/// <param name="coordinate">The coordinate of the Knight.</param>
	/// <param name="is_white">True if the Knight is white, false if black.</param>
	Knight(Coordinate coordinate, bool is_white);

	/// <summary>
	/// Gets all the legal moves for the Knight on the given board.
	/// </summary>
	/// <param name="board">The chess board.</param>
	/// <returns>A vector of Coordinate objects representing the legal moves.</returns>
	std::vector<Coordinate> allLegalMoves(const Board& board) const override;
};
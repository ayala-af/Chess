#pragma once
#include "Piece.h"

/// <summary>
/// Represents the Rook chess piece.
/// </summary>
class Rook : public Piece
{
public:
	/// <summary>
	/// Constructs a Rook object with the given coordinate and color.
	/// </summary>
	/// <param name="coordinate">The coordinate to place the Rook at.</param>
	/// <param name="is_white">Indicates whether the Rook piece is white or black.</param>
	Rook(Coordinate coordinate, bool is_white);


	/// <summary>
	/// Calculates all legal moves for the Rook on the given board.
	/// </summary>
	/// <param name="board">The chess board.</param>
	/// <returns>A vector of coordinates representing legal moves.</returns>
	std::vector<Coordinate> allLegalMoves(const Board& board) const override;
};
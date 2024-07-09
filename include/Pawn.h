#pragma once
#include "Piece.h"

/// <summary>
/// Indicates the direction of movement for white pawns.
/// </summary>
const bool WHITE_GOING_UP = true;

/// <summary>
/// Represents the Pawn chess piece.
/// </summary>
class Pawn : public Piece
{
public:
	/// <summary>
	/// Constructs a Pawn object with the given coordinate and color.
	/// </summary>
	/// <param name="coordinate">The coordinate of the Pawn.</param>
	/// <param name="is_white">True if the Pawn is white, false if black.</param>
	Pawn(Coordinate coordinate, bool is_white);

	/// <summary>
	/// Gets all the legal moves for the Pawn on the given board.
	/// </summary>
	/// <param name="board">The chess board.</param>
	/// <returns>A vector of Coordinate objects representing the legal moves.</returns>
	std::vector<Coordinate> allLegalMoves(const Board& board) const override;
};
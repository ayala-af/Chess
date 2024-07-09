#pragma once
#include "Piece.h"
/// <summary>
/// Class Representing chess Bishop piece. 
/// </summary>
class Bishop : public Piece
{
public:
	/// <summary>
	/// Consracts a Bishop object with the given coordinate and color.
	/// </summary>
	/// <param name="coordinate">to locate the Bishop at.</param>
	/// <param name="is_white">to save Bishop's color.</param>
	Bishop(Coordinate coordinate, bool is_white);

	/// <summary>
	/// Gets a board and returns all leagal moves of Bishop piece on this board.
	/// </summary>
	/// <param name="board">the bord to find all leagal moves at.</param>
	/// <returns></returns>
	std::vector<Coordinate> allLegalMoves(const Board& board) const override;
};
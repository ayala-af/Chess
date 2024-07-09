#pragma once

#include <iostream>
#include"Coordinate.h"
#include "Piece.h"
#include<vector>

class Piece;
/// <summary>
/// Board class represents a chess board.
/// A grid of board._SIZExboard._SIZE where pieces.
/// Tracks of the current state of the game, and the turn of the player.
/// </summary>
class Board
{
public:
	/// <summary>
	/// Size of the board.
	/// </summary>
	static const int _SIZE = 8;

	/// <summary>
	/// Constracts a Board object with the given vector of pieces.
	/// </summary>
	/// <param name="pieces">Vector contains the initial set of pieces to be placed.</param>
	Board(std::vector<Piece*> pieces);

	/// <summary>
	/// Checks if the given coordinate is within the valid range.
	/// </summary>
	/// <param name="coordinate">The coordinate to check.</param>
	/// <returns>True if the position is valid,otherwise false.</returns>
	bool correctPosition(const Coordinate& coordinate) const;

	/// <summary>
	/// Checks if it is currently white's turn to move.
	/// </summary>
	/// <returns>True if it is white's turn, false if it is black's turn.</returns>
	bool isWhiteTurn() const;

	/// <summary>
	/// Changes the turn from white to black, or from black to white.
	/// </summary>
	void changeTurn();

	/// <summary>
	/// Checks if the given coordinate can contain the given player color.
	/// </summary>
	/// <param name="coordinate">The location to check.</param>
	/// <param name="is_white">The player color.</param>
	/// <returns>True if the coordinate can contain the given player color 
	/// (position is nullptr or different color), false otherwise.</returns>
	bool canContain(const Coordinate& coordinate, bool is_white) const;

	/// <summary>
	/// Gets the piece at the specified position on the board.
	/// </summary>
	/// <param name="coordinate">The position on the board.</param>
	/// <returns> Pointer to the Piece at the specified coordinate, or nullptr if there is no piece.</returns>
	Piece* getPiece(const Coordinate& coordinate) const;




	/// <summary>
	/// Moves a piece from the current position to the new position on the board.
	/// </summary>
	/// <param name="current_coordinate">The current position of the piece.</param>
	/// <param name="new_coordinate">The new position to move the piece to.</param>
	void movePiece(const Coordinate& current_coordinate, const Coordinate& new_coordinate);


	/// <summary>
	/// Checks if the specified player is in check.
	/// </summary>
	/// <param name="is_white">The player to check is he in check.</param>
	/// <returns>True if the specified player is in check,otherwise false.</returns>
	bool isCheck(bool is_white) const;

	/// <summary>
	/// Checks if moving a piece from the current position to the new position would result in a check.
	/// </summary>
	/// <param name="src_coordinate">The current position of the piece.</param>
	/// <param name="dst_coordinate">The destenation position of the piece</param>
	/// <returns>True if the move would result in a check, false otherwise.</returns>
	bool isCheckMove(const Coordinate& src_coordinate, const Coordinate& dst_coordinate);


	/// <summary>
	/// Dtor
	/// </summary>
	~Board();
	// Delete the copy constructor and assignment operator
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;
private:
	Piece* m_board[_SIZE][_SIZE]; /* Representing the chess board. */
	bool m_is_white_turn; /*Whether it is white's turn. */

	/// <summary>
	/// Checks if the given index is within the valid range for the chessboard.
	/// </summary>
	/// <param name="i">The index to check.</param>
	/// <returns> True if the index is valid, false otherwise.</returns>
	bool correctIndex(int i) const;

	/// <summary>
	/// Sets a piece at the specified position on the board.
	/// </summary>
	/// <param name="piece">The piece to set.</param>
	/// <param name="new_coordinate">The new coordinate for the piece.</param>
	void setPiece(Piece* piece, const Coordinate& new_coordinate);
};







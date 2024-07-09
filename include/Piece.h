#pragma once
#include "Board.h"
#include <vector>

class Board;


/// <summary>
/// Base class representing a chess piece.
/// </summary>
class Piece
{
private:
	/// <summary>
	/// The name of the piece.
	/// </summary>
	const char m_name;

	/// <summary>
	/// Flag indicating whether the piece is white.
	/// </summary>
	const bool m_is_white;

	/// <summary>
	/// Current location of the piece.
	/// </summary>
	Coordinate m_coordinate;

public:

	/// <summary>
	/// Constructs a Piece object with the given name, coordinate, and color.
	/// </summary>
	/// <param name="name">The name of the piece.</param>
	/// <param name="coordinate">The initial location of the piece.</param>
	/// <param name="is_white">Flag indicating whether the piece is white.</param>
	Piece(char name, Coordinate coordinate, bool is_white)
		: m_name(name), m_is_white(is_white), m_coordinate(coordinate) {}

	/// <summary>
	/// Checks if the piece is white.
	/// </summary>
	/// <returns>True if the piece is white, otherwise false.</returns>
	const bool isWhite() const;

	/// <summary>
	/// Checks if the piece is black.
	/// </summary>
	/// <returns>True if the piece is black, otherwise false.</returns>
	const bool isBlack() const;

	/// <summary>
	 /// Gets the name of the piece.
	 /// </summary>
	 /// <returns>The name of the piece.</returns>
	const char getName() const;

	/// <summary>
	/// Gets the current location of the piece.
	/// </summary>
	/// <returns>The current coordinate of the piece.</returns>
	Coordinate getCoordinate() const;

	/// <summary>
	/// Sets the position of the piece to a new location.
	/// </summary>
	/// <param name="new_coordinate">The new coordinate to set for the piece.</param>
	void setCoordinate(const Coordinate& new_coordinate);

	/// <summary>
	/// Calculates all legal moves for the piece on the given board.
	/// </summary>
	/// <param name="board">The chess board on which the piece resides.</param>
	/// <returns>A vector of coordinates representing legal moves.</returns>
	virtual std::vector<Coordinate> allLegalMoves(const Board& board) const = 0;

	/// <summary>
	/// Destructs the Piece object.
	/// </summary>
	virtual ~Piece() = default;
};

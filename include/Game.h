#pragma once
#include "Board.h"
#include "CodeResponse.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"


/// <summary>
/// Represents the game process of chess.
/// </summary>
class Game
{
	/// <summary>
	/// Pointer to the chess board.
	/// </summary>
	Board* m_board;

	/// <summary>
	/// Converts a character to lowercase.
	/// </summary>
	/// <param name="in">The character to convert.</param>
	/// <returns>The lowercase character.</returns>
	char chartolower(const char& in) const;

	/// <summary>
	/// Converts a string position to a Coordinate.
	/// </summary>
	/// <param name="str_coor">The string position to convert.</param>
	/// <returns>The corresponding Coordinate.</returns>
	Coordinate strToCoordinate(const std::string& str_coor) const;


	/// <summary>
	/// Moves a chess piece from the source position to the destination position.
	/// </summary>
	/// <param name="src_coordinate">The source position of the move.</param>
	/// <param name="dest_coordinate">The destination position of the move.</param>
	/// <returns>A Response object indicating the result of the move.</returns>
	CodeResponse movePiece(const Coordinate& src_coordinate, const Coordinate& det_coordinate);


	/// Constructs a Game object with a string representation of the board.
	/// </summary>
	/// <param name="str_board">The string representation of the board.</param>
	Game(const std::string& str_board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr");

	/// <summary>
	/// Destructs the Game object.
	/// </summary>
	~Game();


	// Delete the copy constructor and assignment operator
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
public:

	/// <summary>
	/// Moves a chess piece based on the given move string.
	/// </summary>
	/// <param name="move">The move string in the format "source destination".</param>
	/// <returns>A Response object indicating the result of the move.</returns>
	CodeResponse movePiece(const std::string& move);

	/// <summary>
	/// Gets the instance of the Game class.
	/// </summary>
	/// <param name="str_board">The string representation of the chess board.</param>
	/// <returns>The singleton instance of the Game class.</returns>
	static Game& getInstance(const std::string& str_board);//!!!!!!!!!!!!
};

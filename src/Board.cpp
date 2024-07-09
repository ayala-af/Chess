#include "Board.h"
#include"Rook.h"

Board::Board(std::vector<Piece*> pieces) : m_is_white_turn(true)
{
	for (int i = 0; i < _SIZE; ++i)
		for (int j = 0; j < _SIZE; ++j)
			m_board[i][j] = nullptr;

	for (auto piece : pieces)
		setPiece(piece, piece->getCoordinate());
}

bool Board::isWhiteTurn() const
{
	return m_is_white_turn;
}

void Board::changeTurn()
{
	m_is_white_turn = !m_is_white_turn;
}

bool Board::correctIndex(int i) const
{
	return (i >= 0 && i < _SIZE);
}

bool Board::correctPosition(const Coordinate& coordinate) const
{
	return (correctIndex(coordinate.getX()) && correctIndex(coordinate.getY()));
}

bool Board::canContain(const Coordinate& coordinate, bool is_white) const
{
	if (correctPosition(coordinate))
	{
		Piece* piece = getPiece(coordinate);
		return piece == nullptr || piece->isWhite() != is_white;
	}
	return false;
}

Piece* Board::getPiece(const Coordinate& coordinate) const
{
	if (!correctPosition(coordinate))
		return nullptr;
	return m_board[coordinate.getX()][coordinate.getY()];
}

void Board::setPiece(Piece* piece, const Coordinate& new_coordinate)
{
	Piece* old_piece = getPiece(new_coordinate);
	if (old_piece != piece)
		delete old_piece;

	m_board[new_coordinate.getX()][new_coordinate.getY()] = piece;
	if (piece)
	{
		Coordinate old_coordinate = piece->getCoordinate();
		if (old_coordinate != new_coordinate)
		{
			m_board[old_coordinate.getX()][old_coordinate.getY()] = nullptr;
			piece->setCoordinate(new_coordinate);
		}
	}
}

void Board::movePiece(const Coordinate& current_coordinate, const Coordinate& new_coordinate)
{
	if (!correctPosition(current_coordinate) || !correctPosition(new_coordinate))
		throw std::invalid_argument("Invalid position.");

	if (current_coordinate == new_coordinate)
		throw std::invalid_argument("Current position equal to the new position.");

	Piece* piece = getPiece(current_coordinate);
	if (!piece)
		throw std::invalid_argument("No piece at current position.");

	setPiece(piece, new_coordinate);
}

bool Board::isCheck(bool is_white) const
{
	for (int i = 0; i < _SIZE; ++i)
		for (int j = 0; j < _SIZE; ++j)
			if (m_board[i][j] != nullptr && m_board[i][j]->isWhite() == is_white)
			{
				std::vector<Coordinate> moves = m_board[i][j]->allLegalMoves(*this);
				for (const auto& move : moves)
					if (m_board[move.getX()][move.getY()] != nullptr && m_board[move.getX()][move.getY()]->getName() == 'k')
						return true;
			}

	return false;
}

bool Board::isCheckMove(const Coordinate& src_coordinate, const Coordinate& dst_coordinate)
{
	Piece* src_piece = getPiece(src_coordinate);
	Piece* dest_piece = getPiece(dst_coordinate);

	// fake move
	m_board[src_coordinate.getX()][src_coordinate.getY()] = nullptr;
	m_board[dst_coordinate.getX()][dst_coordinate.getY()] = src_piece;
	src_piece->setCoordinate(dst_coordinate);

	// Check if this move causes the mover to be in check
	bool is_check_move = isCheck(src_piece->isBlack());

	// Restore the situation to its original state
	src_piece->setCoordinate(src_coordinate);
	m_board[src_coordinate.getX()][src_coordinate.getY()] = src_piece;
	m_board[dst_coordinate.getX()][dst_coordinate.getY()] = dest_piece;

	return is_check_move;
}

Board::~Board()
{
	for (int i = 0; i < _SIZE; ++i)
		for (int j = 0; j < _SIZE; ++j)
			if (m_board[i][j])
			{
				delete m_board[i][j];
				m_board[i][j] = nullptr;
			}
}

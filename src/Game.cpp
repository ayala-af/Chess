#include "Game.h"

char Game::chartolower(const char& in) const
{
	if (in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}

Coordinate Game::strToCoordinate(const std::string& str_coor) const
{
	int i = chartolower(str_coor[0]) - 'a';
	int j = str_coor[1] - '1';
	Coordinate pos(i, j);
	return pos;
}

CodeResponse Game::movePiece(const Coordinate& src_coordinate, const Coordinate& dst_coordinate)
{
	Piece* source_piece = m_board->getPiece(src_coordinate);

	//no piece at the source  
	if (source_piece == nullptr)
		return CodeResponse::NO_PIECE;

	//If the piece in the source is piece of your opponent

	if (m_board->isWhiteTurn() != source_piece->isWhite())
		return CodeResponse::OPPONENT_PIECE;

	//If there one of your pieces at the destination 
	if (!m_board->canContain(dst_coordinate, source_piece->isWhite()))
		return CodeResponse::YOUR_PIECE_AT_DESTINATION;

	std::vector<Coordinate> all_moves = source_piece->allLegalMoves(*m_board);

	// illegal movement of that piece 
	if (std::find(all_moves.begin(), all_moves.end(), dst_coordinate) == all_moves.end())
		return CodeResponse::ILLEGAL_MOVEMENT;

	// this movement will cause you checkmate
	if (m_board->isCheckMove(src_coordinate, dst_coordinate))
		return CodeResponse::CHECKMATE_MOVE;

	m_board->movePiece(src_coordinate, dst_coordinate);
	m_board->changeTurn();

	// the last movement was legal and cause check
	if (m_board->isCheck(source_piece->isWhite()))
		return CodeResponse::LEGAL_MOVEMENT_CHECK;

	//the last movement was legal, next turn
	return CodeResponse::LEGAL_MOVEMENT_NEXT_TURN;
}

Game::Game(const std::string& str_board) : m_board(nullptr)
{

	std::vector<Piece*> all_piece;
	for (int i = 0; i < str_board.size(); ++i)
	{
		char c = str_board[i];
		if (c == '#')
			continue;

		bool is_white = (c >= 'A' && c <= 'Z');
		char piece_char = chartolower(c);
		Coordinate pos(i / m_board->_SIZE, i % m_board->_SIZE);

		Piece* piece = nullptr;
		switch (piece_char)
		{

		case 'p':
			piece = new Pawn(pos, is_white);
			break;
		case 'n':
			piece = new Knight(pos, is_white);
			break;

		case 'b':
			piece = new Bishop(pos, is_white);
			break;

		case 'r':
			piece = new Rook(pos, is_white);
			break;

		case 'q':
			piece = new Queen(pos, is_white);;
			break;

		case 'k':
			piece = new King(pos, is_white);
			break;


		}
		if (piece)
			all_piece.push_back(piece);


	}
	m_board = new Board(all_piece);

}

CodeResponse Game::movePiece(const std::string& move)
{
	if (move.size() != 4)
		//invalid argument- len =!4
		return  CodeResponse::ILLEGAL_MOVEMENT;
	Coordinate src_coor = strToCoordinate(move.substr(0, 2));
	if (!m_board->correctPosition(src_coor))
		//invalid argument -source coordinate doesnt exsist
		return  CodeResponse::ILLEGAL_MOVEMENT;
	Coordinate dest_coor = strToCoordinate(move.substr(2, 2));
	if (!m_board->correctPosition(dest_coor))
		//invalid argument - dest coordinate doesnt exsist
		return  CodeResponse::ILLEGAL_MOVEMENT;

	return movePiece(src_coor, dest_coor);
}

Game& Game::getInstance(const std::string& str_board)
{
	static Game instance(str_board);
	return instance;
}

Game::~Game()
{
	delete m_board;
	m_board = nullptr;
}

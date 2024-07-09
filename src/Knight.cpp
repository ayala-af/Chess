#include "Knight.h"

Knight::Knight(Coordinate coordinate, bool is_white) :Piece('n', coordinate, is_white) {}

std::vector<Coordinate> Knight::allLegalMoves(const Board& board) const
{
    std::vector<Coordinate> moves;
    Coordinate current_coordinate = getCoordinate();
    std::vector<Coordinate> available_moves = { 
        Coordinate(-2, -1), Coordinate(-2, 1), Coordinate(2, 1), Coordinate(2, -1),
        Coordinate(-1, -2), Coordinate(-1, 2), Coordinate(1, 2), Coordinate(1, -2) };

    for (Coordinate &a_move : available_moves)
    {
        Coordinate new_coordinate = current_coordinate + a_move;
        if (board.canContain(new_coordinate, isWhite()))
            moves.push_back(new_coordinate);
    }
    return moves;
}

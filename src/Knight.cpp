#include "Knight.h"

Knight::Knight(bool isWhite)
    : Piece(isWhite ? 'K' : 'k', isWhite, PieceType::KNIGHT){}


//map out knight movement, moves in L shape
bool Knight::isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const{
    //use if branching to determimne if moving more vertically or horizontally, check for validity
    if((startX + 1 != endX) && (startX - 1 != endX)){
        return (((startX + 2 == endX) || (startX - 2 == endX)) && ((startY + 1 == endY) || (startY - 1 == endY)));
    }
    else{
        return (((startX + 1 == endX) || (startX - 1 == endX)) && ((startY + 2 == endY) || (startY -2 == endY)));
    }
}


#include "Bishop.h"

Bishop::Bishop(bool isWhite) 
    : Piece(isWhite ? 'B' : 'b', isWhite, PieceType::BISHOP){}

bool Bishop::isValidMove(int startX, int startY, int endX, int endY)const{

    return ((abs(endX-startX)) == (abs(endY-startY)));
}



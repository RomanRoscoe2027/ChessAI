#include "Rook.h"

Rook::Rook(bool isWhite) 
    : Piece(isWhite ? 'R' : 'r', isWhite, PieceType::ROOK){}

bool Rook::isValidMove(int startX, int startY, int endX, int endY)const{
    return (startX == endX || startY ==endY);
}



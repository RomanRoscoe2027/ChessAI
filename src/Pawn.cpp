#include "Pawn.h"

Pawn::Pawn(bool isWhite)
    : Piece(isWhite ? 'P' : 'p', isWhite, PieceType::PAWN){}

bool Pawn::isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const{
    int start_rank = isWhite ? 0:7;
}

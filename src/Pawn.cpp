#include "Pawn.h"

Pawn::Pawn(bool isWhite)
    : Piece(isWhite ? 'P' : 'p', isWhite, PieceType::PAWN){}

bool Pawn::isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const{
    const int startRank = isWhite ? 1 : 6; // white pawns start on rank 1 (y=1), black on rank 6 (y=6)
    //Need dX and dY for simplicity in all classes to be honest, another change realized I should make
    const int dX = endX - startX;
    const int dY = endY - startY;
    /*google and robots think a directionally variable important...
    would certainly say so for long path movements where incrementing is necessary
    to check all obstruction squares, will start using it with pawn for that reason.*/
    const int dir = isWhite ? 1 : -1;

    // single forward (one square)
    if (dX == 0 && dY == dir){
        return grid.isEmpty(endX,endY);
    }

    // double step from starting rank (two squares)
    if (dX == 0 && dY == 2*dir && startY == startRank){
        // intermediate square must be empty and destination must be empty
        if (!grid.isEmpty(startX, startY + dir)) return false;
        return grid.isEmpty(endX, endY);
    }

    // take diag as pawn if opposing piece obvious
    if (std::abs(dX) == 1 && dY == dir) {
        const Piece* target = grid.getPiece(endX, endY);
        if (target != nullptr && target->getIsWhite() != this->isWhite) {
            return true; 
        }
    }

    // en-passant and promotion not implemented here
    return false;
}

/*MUST add en passant as well as promotion when time comes.
 Don't anticipate it being too bad though.
 For now basic move logic and taking for pawns is excellent development.
*/
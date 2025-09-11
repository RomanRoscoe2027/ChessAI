#include "Rook.h"

Rook::Rook(bool isWhite) 
    : Piece(isWhite ? 'R' : 'r', isWhite, PieceType::ROOK){}

bool Rook::isValidMove(int startX, int startY, int endX, int endY, const Board& grid)const{
    const int dX = endX - startX;
    const int dY = endY-startY;
    if (dX != 0 && dY != 0) return false; //error check diag moves
    if (startX == endX && startY == endY) return false; //error check no movement essentially
    
    // moving right
    if (dX > 0) {
        for (int step = 1; step < dX; step++) {
            //for all directions, use step to check path at every square to make sure no obstruction
            if (!grid.isEmpty(startX + step, startY)) {
                //obv if not empty its not a valid move
                return false;
            }
       
        }
    }
    // moving left
    else if (dX < 0) {
        for (int step = -1; step > dX; step--) {
            if (!grid.isEmpty(startX + step, startY)) {
                return false;
            }
        
        }
    }
    // moving up
    else if (dY > 0) {
        for (int step = 1; step < dY; step++) {
            if (!grid.isEmpty(startX, startY + step)) {
                return false;
            }
        
        }
    }
    // moving down
    else if (dY < 0) {
        for (int step = -1; step > dY; step--) {
            if (!grid.isEmpty(startX, startY + step)) {
                return false;
            }
        
        }
    }

    const Piece* target = grid.getPiece(endX, endY);
    if (target == nullptr) {
        return true; // moving into empty square
    } else {
        // can only take enemy piece
        return (target->getIsWhite() != this->isWhite);
    }
    }
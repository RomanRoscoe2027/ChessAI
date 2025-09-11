#include "Knight.h"

Knight::Knight(bool isWhite)
    : Piece(isWhite ? 'K' : 'k', isWhite, PieceType::KNIGHT){}


//map out knight movement, moves in L shape
bool Knight::isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const{
    /*Use if branching to determimne if moving more vertically or horizontally, check for validity
    
    if((startX + 1 != endX) && (startX - 1 != endX)){
        return (((startX + 2 == endX) || (startX - 2 == endX)) && ((startY + 1 == endY) || (startY - 1 == endY)));
    }
    else{
        return (((startX + 1 == endX) || (startX - 1 == endX)) && ((startY + 2 == endY) || (startY -2 == endY)));
    }
        This was my old version of checking knight logic. Perfectly valid, 
        and has no errors however its a mess to read,
        so for the sake of other devs and the readers
        
        I am going to not be annoying and make it pretty 
        and aligned with the rest of my code.
        
        Just keeping this as a reminder however of what I had done prior, messy means wrong
        but not incorrect. */
    int dX = std::abs(endX - startX);
    int dY = std::abs(endY - startY);
    
    if (!((dX == 2 && dY == 1) || (dX == 1 && dY == 2))) {return false;}
    // valid knight move if it's 2 and 1 in either order 
    const Piece* target = grid.getPiece(endX, endY);
    if (target != nullptr && target->getIsWhite() != this->isWhite) {
        return true;
    }
    if (target == nullptr) {
        return ;
    }
    else {return false;}      
}


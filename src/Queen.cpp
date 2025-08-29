#include "Queen.h"

Queen::Queen(bool isWhite) 
    : Piece(isWhite ? 'Q' : 'q', isWhite, PieceType::QUEEN){}

bool Queen::isValidMove(int startX, int startY, int endX, int endY, const Board& grid)const{
    if (startX == endX && startY == endY) return false;
    //check above rule for every piece, as most pieces by current rules could move nowhere and it would be considered valid
    if((abs(endX-startX)) == (abs(endY-startY))){
        return true;
    }
    else if(startX == endX || startY ==endY){
        return true;
    }
    else return false;
}



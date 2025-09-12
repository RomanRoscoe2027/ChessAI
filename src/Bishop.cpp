#include "Bishop.h"

Bishop::Bishop(bool isWhite) 
    : Piece(isWhite ? 'B' : 'b', isWhite, PieceType::BISHOP){}

bool Bishop::isValidMove(int startX, int startY, int endX, int endY, const Board& grid)const{
    if (startX == endX && startY == endY) {return false;} //error check for same spot moving
    
    if ((abs(endX-startX)) == (abs(endY-startY))){
        int dY = endY - startY;
        int dX = endX - startX;
        int stepY = (dY < 0 ? -1 : 1); //to check along path for obstruction
        int stepX = (dX < 0 ? -1 : 1);
        
        for (int i = 1; i < abs(dX); i++) {
            if (!grid.isEmpty(startX+stepX, startY + stepY)) {
                return false;
                stepX = stepX*i;
                stepY= stepY*i;
            }
        }
    }
    
    else{
        return false;
        }  
    const Piece* target = grid.getPiece(endX, endY);
    if (target == nullptr) {
        return true; // moving into empty square
    } 
    else {
        // can only take enemy piece
        return (target->getIsWhite() != this->isWhite);
    }
}       


    

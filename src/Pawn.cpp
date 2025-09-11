#include "Pawn.h"

Pawn::Pawn(bool isWhite)
    : Piece(isWhite ? 'P' : 'p', isWhite, PieceType::PAWN){}

bool Pawn::isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const{
    const int startRank = isWhite ? 0:7;
    //Need dX and dY for simplicity in all classes to be honest, another change realized I should make
    const int dX = endX - startX;
    const int dY = endY-startY;
    /*google and robots think a directionally variable important...
    would certainly say so for long path movements where incrementing is necessary
    to check all obstruction squares, will start using it with pawn for that reason.*/
    const int dir = isWhite ? 1 : -1;
    //define logic just for single step w obstruction

    //if(grid.inBounds(endX,endY) == false)

    if (dir == 1  && dY ==1){
        return(grid.isEmpty(endX,endY));
    }
    else if (dir == -1 && dY==-1){
        return(grid.isEmpty(endX,endY));
    }
    //define logic for just double step w obstruction

    if (dir == -1 && dY == -2 && startY ==startRank){
        return(grid.isEmpty(endX,endY) && grid.isEmpty(endX+dir, endY+dir)); //check first sq too
    }
    else if (dir == 1 && dX ==2 && startY == startRank){
        return(grid.isEmpty(endX,endY) && grid.isEmpty(endX+dir, endY+dir));//same
    }
    
    //take diag as pawn if opposing piece obv opposition
    if (abs(dX) == 1 && dY == dir) {
        const Piece* target = grid.getPiece(endX, endY);
        if (target != nullptr && target->getIsWhite() != this->isWhite) {
            return true; 
        }
    }

}

/*MUST add en passant as well as promotion when time comes.
 Don't anticipate it being too bad though.
 For now basic move logic and taking for pawns is excellent development.
*/
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:

    Queen(bool isWhite);  
    // need to know if white or black to determine symbol as well
    bool isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const override; 
    //declare move logic
    

};

#endif //QUEEN_H

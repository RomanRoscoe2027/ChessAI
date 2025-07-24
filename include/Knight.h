#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight: public Piece{
    public:
        Knight(bool isWhite); // color determines everything else

        bool isValidMove(int startX, int startY, int endX, int endY) const override;
        //check if logical move, will implement blocking logic and such later

}


#endif //KNIGHT_H

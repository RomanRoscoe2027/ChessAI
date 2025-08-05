#ifndef PIECE_H
#define PIECE_H

#include <string>
enum class PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};
class Piece {
protected:
    char symbol;
    bool isWhite;
    PieceType type; 
public:
    Piece(char symbol, bool isWhite, PieceType type);
    virtual ~Piece();

    char getSymbol() const;
    bool getIsWhite() const;
    PieceType getPieceType () const;
    
    virtual bool isValidMove(int startX, int startY, int endX, int endY) const = 0;
    
};

#endif // PIECE_H

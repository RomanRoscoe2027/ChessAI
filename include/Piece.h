#ifndef PIECE_H
#define PIECE_H

class Board;

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
    char symbol; //classifies piece type
    bool isWhite; //white or black piece, setter, important not to make public or else buggy
    PieceType type; //the classification of piece
public:
    Piece(char symbol, bool isWhite, PieceType type);
    
    virtual ~Piece(); //destructor needed for polymorphism

    char getSymbol() const; //getter symbol
    
    bool getIsWhite() const; //getter is white
    
    PieceType getPieceType () const;
    
    virtual bool isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const = 0;
    
};

#endif // PIECE_H

#include "Piece.h"

Piece::Piece(char symbol, bool isWhite, PieceType type): symbol(symbol), isWhite(isWhite), type(piece) {}

Piece::~Piece() {}

char Piece::getSymbol() const{
    return symbol;
}
bool Piece::getIsWhite() const {
    return isWhite;
}
PieceType Piece::getPieceType() const{
    return type;
}


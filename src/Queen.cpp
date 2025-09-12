#include "Queen.h"


Queen::Queen(bool isWhite) 
    : Piece(isWhite ? 'Q' : 'q', isWhite, PieceType::QUEEN) {}

bool Queen::isValidMove(int startX, int startY, int endX, int endY, const Board& grid) const {
    if (startX == endX && startY == endY) return false; // can't stay in place

    int dX = endX - startX;
    int dY = endY - startY;

    // must be straight or diagonal
    if (!(dX == 0 || dY == 0 || std::abs(dX) == std::abs(dY))) return false;

    int stepX = (dX == 0 ? 0 : (dX < 0 ? -1 : 1));
    int stepY = (dY == 0 ? 0 : (dY < 0 ? -1 : 1));

    //for queen distance allows us to check both rook and bishop logic easy
    int distance = std::max(std::abs(dX), std::abs(dY));
    for (int i = 1; i < distance; i++) {
        if (!grid.isEmpty(startX + i * stepX, startY + i * stepY)) {
            return false; // path blocked
        }
    }

    
    const Piece* target = grid.getPiece(endX, endY);
    if (target == nullptr) {
        return true;
    } else {
        return target->getIsWhite() != this->getIsWhite();
    }
}

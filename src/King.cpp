#include "King.h"
#include <cmath>

bool King::isValidMove(int startX, int startY, int endX, int endY, const Board& board) const noexcept {
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // King moves 1 square in any direction
    return (dx <= 1 && dy <= 1 && (dx + dy > 0));
}

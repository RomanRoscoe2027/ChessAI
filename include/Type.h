#ifndef TYPE_H
#define TYPE_H

#include <cstdint>

enum class PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

enum MoveFlags : uint8_t {
    //each  bit ==1 represents flag as true or not.
    Quiet            = 0,
    Capture          = 1u << 0,
    //shifts unsigned int, don't need overflow here
    DoublePawnPush   = 1u << 1,
    EnPassant        = 1u << 2,
    KingSideCastle   = 1u << 3,
    QueenSideCastle  = 1u << 4,
    Promotion        = 1u << 5,
    Pin              = 1u << 6,  // mover was pinned in the pre-move position
    // (bit 7 free for future use)
    
};



struct Move {
    
    PieceType moved;
    PieceType captured;
    PieceType promo;
    uint8_t flags = Quiet;

    bool is_capture()   const { return flags & Capture; }
    bool is_promotion() const { return flags & Promotion; }
    bool is_enpassant() const { return flags & EnPassant; }
    bool is_castle()    const { return flags & (KingSideCastle | QueenSideCastle); }
};

struct MoveList {
    Move data[256];
    int  count = 0;
    void clear() { count = 0; }
    void add(const Move& m) { data[count++] = m; }
};
#endif // TYPE_H
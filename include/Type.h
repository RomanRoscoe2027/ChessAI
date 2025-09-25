#ifndef TYPE_H
#define TYPE_H

#include <cstdint>
enum class Color : std::uint8_t { WHITE = 0, BLACK = 1 };
constexpr Color opposite(Color color) { return color == Color::WHITE ? Color::BLACK : Color::WHITE; }
//very important everything regarding moves is quick, stores little overhead
//if chess engine implemented will require fast execution

enum class PieceType : std::uint8_t {
    NONE  = 0, 
    PAWN  = 1,
    ROOK  = 2,
    KNIGHT= 3,
    BISHOP= 4,
    QUEEN = 5,
    KING  = 6
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


using Square = std::uint8_t;                 // 0..63

// Encode/decode (keep inline in header for zero call overhead)
inline Square encode_square(int x, int y)      { return Square(y * 8 + x); }
inline constexpr int    square_x(Square s)               { return s % 8; }
inline constexpr int    square_y(Square s)               { return s / 8; }
/*didn't understand what the point of all this was at first, I now understand,
essentially boiling down our 4 ints which were about 32 bytes, to 2 8 bit
numbers for sq_x and sq_y*/

struct Move {
    Square from = 0;  //endX and endY
    Square to = 0;   //startX and startY
    //creating Move object
    PieceType moved = PieceType::NONE;
    PieceType captured = PieceType::NONE;
    PieceType promo = PieceType::NONE;
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
    void add(const Move& move) { data[count++] = move; }
};
#endif // TYPE_H
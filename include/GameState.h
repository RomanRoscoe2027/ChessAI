// GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include "Type.h"
#include "Board.h"

class GameState {
public:
    explicit GameState(Color start = Color::WHITE) noexcept;

    bool makeMove(const Move& m) noexcept;
    void unmakeMove() noexcept;

    

private:

    struct StateDelta {
        Move move;
        std::uint8_t castling_before{};
        Square ep_before{64}; // NO_SQ
        std::uint16_t halfmove_before{};
        std::uint16_t fullmove_before{};
        Color stm_before{Color::WHITE};
        PieceType captured_type{PieceType::NONE};
        Square captured_on{64};
        
    };

    Board board_{};
    Color stm_{Color::WHITE};
    std::vector<StateDelta> history_; 
};

#endif // GAMESTATE_H

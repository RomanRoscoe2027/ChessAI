#include "GameState.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <utility>
#include <memory>

GameState::GameState(Color start) noexcept
    : board_(), stm_(start), history_() {}

bool GameState::makeMove(const Move& m) noexcept {
    StateDelta delta{};
    delta.move = m;
    delta.stm_before = stm_;
    
    // decode squares
    int sx = square_x(m.from);
    int sy = square_y(m.from);
    int tx = square_x(m.to);
    int ty = square_y(m.to);

    // validate there is a piece
    const Piece* p = board_.getPiece(sx, sy);
    if (!p) return false;

    // enforce side-to-move: piece color must match stm_
    Color pieceColor = p->getIsWhite() ? Color::WHITE : Color::BLACK;
    if (pieceColor != stm_) return false;

    // validate the piece allows this move
    if (!p->isValidMove(sx, sy, tx, ty, board_)) return false;

    // perform move on board: movePiece returns any captured piece
    std::unique_ptr<Piece> captured = board_.movePiece(sx, sy, tx, ty);
    if (captured) {
        delta.captured_type = captured->getPieceType();
        delta.captured_on = m.to;
        delta.captured_piece = std::move(captured);
    } else {
        delta.captured_type = PieceType::NONE;
        delta.captured_on = 64;
    }

    // push delta (stores captured piece)
    history_.push_back(std::move(delta));

    // switch side to move
    stm_ = opposite(stm_);

    return true;
}

void GameState::unmakeMove() noexcept {
    if (history_.empty()) return;
    StateDelta delta = std::move(history_.back());
    history_.pop_back();

    // decode move
    int sx = square_x(delta.move.from);
    int sy = square_y(delta.move.from);
    int tx = square_x(delta.move.to);
    int ty = square_y(delta.move.to);

    // move piece back from to -> from
    std::unique_ptr<Piece> moved = board_.movePiece(tx, ty, sx, sy);

    // restore exact captured piece if any
    if (delta.captured_piece) {
        board_.placePiece(square_x(delta.captured_on), square_y(delta.captured_on), std::move(delta.captured_piece));
    }

    // If move returned the moved piece into 'moved', place it back onto source (movePiece already moved it)
    if (moved) {
        // moved currently holds the piece that was moved back to source; ensure source has it
        board_.placePiece(sx, sy, std::move(moved));
    }

    // restore side to move
    stm_ = delta.stm_before;
}

bool GameState::canMove(const Move& m, std::string& reason) const {
    int sx = square_x(m.from);
    int sy = square_y(m.from);
    int tx = square_x(m.to);
    int ty = square_y(m.to);

    const Piece* p = board_.getPiece(sx, sy);
    if (!p) { reason = "no piece at source"; return false; }
    Color pieceColor = p->getIsWhite() ? Color::WHITE : Color::BLACK;
    if (pieceColor != stm_) { reason = "not your side to move"; return false; }
    if (!p->isValidMove(sx, sy, tx, ty, board_)) { reason = "piece disallows move"; return false; }
    return true;
}





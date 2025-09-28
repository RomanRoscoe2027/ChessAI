# ChessAI (main)

This repository contains a small C++ chess engine and a minimal command-line interface (CLI) implemented in `main`. This README explains how the code is organised, what the current build produces, how to run the CLI, and how to play with the current functionality on the `main` branch.

Quick summary
- Language: C++20
- Build: CMake (recommended)
- Executable: `build/bin/chess_cli`

Prerequisites
- A C++ compiler with C++20 support (g++ 10+/clang 12+ recommended)
- CMake (>= 3.15)
- make or ninja

Build (CMake)
1. From the project root, configure the build directory:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```

2. Build the project:

```bash
cmake --build build --config Release -j$(nproc)
```

3. Run the CLI:

```bash
./build/bin/chess_cli
```

Quick alternative (single-command compile)
```bash
g++ -std=c++20 -Iinclude src/*.cpp -o demo
./demo
```

How the code is organised
- `include/` — public headers:
	- `Board.h` — board storage (8x8 grid of `std::unique_ptr<Piece>`), `movePiece`, `placePiece`, `printBoard` and helpers.
	- `Piece.h` and per-piece headers (`Pawn.h`, `Rook.h`, etc.) — polymorphic piece base class and concrete pieces. Each piece implements `isValidMove(...)`.
	- `GameState.h` — higher level game state: internal `Board board_`, side-to-move, move history (undo), and helpers like `makeMove`, `unmakeMove`, `canMove`, and `printBoard()`.
	- `Type.h` — shared types (Color, PieceType, Square, Move struct, helpers to encode/decode squares).
- `src/` — implementations and `main.cpp` (the CLI).

What the program currently supports (functionality in `main`)
- An ASCII board printout and a simple interactive prompt.
- Enter moves in the format `e2e4` (four characters: source square then target square). Example: `e2e4` moves the white pawn from e2 to e4.
- The engine enforces side-to-move (White then Black) and calls each piece's `isValidMove(...)` for basic per-piece legality.
- Captures are supported and stored in a history stack so moves can be undone programmatically (`GameState::unmakeMove()` exists), though the default CLI currently does not expose an `undo` command.

Limitations (important)
- This is an engine skeleton / demo, not a full chess rules implementation. Missing or partial features:
	- No check/checkmate detection: moves that leave the king in check are not prevented.
	- No castling, en-passant, or pawn promotion handling.
	- Piece `isValidMove(...)` implementations are basic; sliding pieces may not check all pin situations.

How to play (step-by-step)
1. Run the CLI:

```bash
./build/bin/chess_cli
```

2. At the prompt enter moves like `e2e4` (no spaces). The board will print after each successful move.
3. To quit, enter `q` or `quit` or send EOF (Ctrl+D).

Example session
```
White> e2e4
<board prints showing pawn moved>
Black> e7e5
<board prints showing black pawn moved>
White> g1f3
<board prints showing knight moved>
```

Where to extend the project
- Add full move legality: check detection, pin detection, and move filtering.
- Implement pawn promotion, en-passant, and castling.
- Add an `undo` command to the CLI that calls `GameState::unmakeMove()`.
- Add FEN import/export and test suites for move generation.



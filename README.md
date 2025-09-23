# ChessAI

A C++ chess application built from scratch with a focus on **modern C++ design**, **expandability**, and **future AI/GUI integration**.  
This project began as a way to practice object-oriented programming, memory management, and data structure design — and is growing toward a complete chess engine with AI capabilities and a graphical interface.

---

## Current Features
- **Chess Engine Foundations**
  - Object-oriented class hierarchy for pieces (`Pawn`, `Rook`, `Bishop`, `Knight`, `Queen`, `King`)
  - Polymorphism for piece movement rules
  - Smart pointer memory management (`std::unique_ptr`)  
  - Data structure to represent and display the board
- **Move Logic**
  - Legal move validation for implemented pieces
  - Obstruction detection and basic take logic
- **Development Environment**
  - Built with **CMake** for cross-platform support
  - Version controlled with **Git/GitHub**

---

## Roadmap
Planned features include:
- **Full Chess Engine**
  - Complete and optimized move generation
  - Turn order, check/checkmate detection, castling, en passant

- **GUI* (goal)
  - Cross-platform graphical user interface
  - Potential frameworks: **SDL2** or **Qt**
  - Drag-and-drop piece movement

---

## Tech Stack
- **Language:** C++20
- **Build System:** CMake
- **Tools:** Git, GitHub, VS Code, g++/Clang
- **Environment:** Linux (Ubuntu/WSL)

---

cmake_minimum_required(VERSION 3.22)

project(ChessAI LANGUAGES CXX)

# --- C++ standard ---
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Output dirs (puts binaries in build/bin) ---
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# --- Engine library (no main()) ---
add_library(chess STATIC
    src/AI.cpp
    src/Bishop.cpp
    src/Board.cpp
    src/Game.cpp
    src/King.cpp
    src/Knight.cpp
    src/Pawn.cpp
    src/Piece.cpp
    src/Queen.cpp
    src/Rook.cpp
)

# Public headers for anyone linking 'chess'
target_include_directories(chess
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Warnings (nice and strict)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(chess PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
  target_compile_options(chess PRIVATE /W4 /permissive-)
endif()

# --- App executable (this has main()) ---
add_executable(chess_cli
    src/main.cpp
)

target_link_libraries(chess_cli PRIVATE chess)



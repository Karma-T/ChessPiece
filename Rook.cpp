//Author: Karma Tsewang
//Date: Feb 11 2025
//Defining the rook class.

#include <iostream>
#include <string>
#include "Rook.hpp"

// Default Constructor
Rook::Rook() : ChessPiece() {
    castle_moves_left = 3;
}

// Parameterized Constructor
Rook::Rook(const std::string &color, const int &row, const int &column, const bool &movingUp, const int &castle_moves_left) : ChessPiece(color, row, column, movingUp), castle_moves_left_(castle_moves_left < 0 ? 0 : castle_moves_left) {}

// Accessors & Mutators
bool Rook::canCastle(const ChessPiece &other) const {
    return (castle_moves_left_ > 0 && // Must have at least 1 castle move left
            color_ == other.getColor() && // Both pieces must have the same color
            row_ == other.getRow() && // Both pieces must be in the same row
            (column_ == other.getColumn() + 1 || column_ == other.getColumn() - 1)); // Adjacent columns
}

int Rook::getCastleMovesLeft() const { return castle_moves_left_; }



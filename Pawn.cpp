//Author: Karma Tsewang
//Date: Feb 11 2025
//Defining the pawn class.

#include <iostream>
#include <string>
#include "Pawn.hpp"

// Default Constructor
Pawn::Pawn() : ChessPiece() {
    double_jumpable_ = false;
}

// Parameterized Constructor
Pawn::Pawn(const std::string &color, const int &row, const int &column, const bool &movingUp, const bool &double_jumpable) : ChessPiece(color, row, column, movingUp), double_jumpable_(double_jumpable) {}

// Accessors & Mutators
bool Pawn::canDoubleJump() const { return double_jumpable_; }

void Pawn::toggleDoubleJump() { double_jumpable_ = !double_jumpable_; }

bool Pawn::canPromote() const {
    return (movingUp_ && row_ == BOARD_LENGTH - 1) || (!movingUp_ && row_ == 0);
}

void Pawn::runOutput() const{
    display();
}

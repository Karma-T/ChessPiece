//Author: Karma Tsewang
//Date: Feb 11 2025
//Defining the pawn class.

#include <iostream>
#include <string>
#include <cctype> //isaplha and toupper functions
#include "Pawn.hpp"

using namespace std;

Pawn::Pawn(){
    color_ = "BLACK";
    row_ = -1;
    column_ = -1;
    movingUp_ = false;
    double_jumpable_ = false;
}

// parameterized constructor
Pawn::Pawn(const string& color, const int& row, const int& column, const bool& movingUp, const bool& double_jumpable) : ChessPiece(color, row, column, movingUp), double_jumpable_(double_jumpable) {
    if (!ValidColor(color)) { //if color is not valid
        color_ = "BLACK";
    }

    if (!ValidPosition(row) || !ValidPosition(column)) { //if row and column is not valid
        row_ = -1;
        column_ = -1;
    }
}

bool Pawn::canDoubleJump() const { //returns if the pawn can double jump
    return double_jumpable_;
}

void Pawn::toggleDoubleJump() { //toggle double jump
    double_jumpable_ = !double_jumpable_;
}

bool Pawn::canPromote() const {//returns if the pawn can promote
    if (movingUp_) {
        return (row_ == BOARD_LENGTH - 1); //if the pawn is on the last row
    } else {
        return (row_ == 0); //if the pawn is on the first row
    }
}

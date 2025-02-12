//Author: Karma Tsewang
//Date: Feb 11 2025
//Defining the rook class.

#include <iostream>
#include <string>
#include "Rook.hpp"

using namespace std;
Rook::Rook(){
    color_ = "BLACK";
    row_ = -1;
    column_ = -1;
    movingUp_ = false;
    castle_moves_left_ = 3;
}

// default constructor
Rook::Rook(const string& color, const int& row, const int& column, const bool& movingUp, const int& castleMoves) : ChessPiece(color_, row_, column_, movingUp_), castle_moves_left_(3) {
    if (!ValidColor(color)) { //if color is not valid
        color_ = "BLACK";
    } else {
        color_ = UpperCase(color);
    }

    if (!ValidPosition(row) || !ValidPosition(column)) { //if row and column is not valid
        row_ = -1;
        column_ = -1;
    }

    if (castle_moves_left_ < 0) { //castle moves cannot be negative
        castle_moves_left_ = 0;
    }
}

int Rook::getCastleMovesLeft() const { //returns the number of castle moves left
    return castle_moves_left_;
}

bool Rook::canCastle() const { //returns if the rook can castle
    return castle_moves_left_ > 0; //castle moves left
}

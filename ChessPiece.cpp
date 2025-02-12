//Author: Karma Tsewang
//Date: Feb 11 2025
//Defining the chess piece base class.

#include <iostream>
#include <string>
#include <cctype> //isaplha and toupper functions
#include "ChessPiece.hpp"

using namespace std;

//default constructor
ChessPiece::ChessPiece() {
    color_ = "BLACK";
    row_ = -1;
    column_ = -1;
    movingUp_ = false;
}

//parameterized constructor
ChessPiece::ChessPiece(const string& color, const int& row, const int& column, const bool& movingUp) {
    if (ValidColor(color)) {
        color_ = UpperCase(color);
    } else {
        color_ = "BLACK";
    }

    if (ValidPosition(row) && ValidPosition(column)) {
        row_ = row;
        column_ = column;
    } else {
        row_ = -1;
        column_ = -1;
    }

    movingUp_ = movingUp;
}

bool ChessPiece::ValidColor(const string& color) const { //check if color is valid
    for (char c : color) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

string ChessPiece::UpperCase(const string& color) const { //convert string color to uppercase
    string color2 = color; //copy of color to convert to uppercase
    for (char& c : color2) {
        c = toupper(c); //each character to uppercase
    }
    return color2;
}

bool ChessPiece::ValidPosition(int value) const { //check if row and column is within valid range
    return (value >= 0 && value < BOARD_LENGTH);
}

string ChessPiece::getColor() const {
    return color_;
}

bool ChessPiece::setColor(const string& color) {
    if (ValidColor(color)) {
        color_ = UpperCase(color);
        return true;
    }
    return false;
}

int ChessPiece::getRow() const {
    return row_;
}

int ChessPiece::getColumn() const {
    return column_;
}

void ChessPiece::setRow(const int& row) {
    if (ValidPosition(row)) {
        row_ = row;
    } else {
        row_ = -1;
        column_ = -1;
    }
}

void ChessPiece::setColumn(const int& column) {
    if (ValidPosition(column)) {
        column_ = column;
    } else {
        row_ = -1;
        column_ = -1;
    }
}

bool ChessPiece::isMovingUp() const {
    return movingUp_;
}

void ChessPiece::setMovingUp(const bool& movingUp) {
    movingUp_ = movingUp;
}

void ChessPiece::Display() const {
    if (row_ != -1 && column_ != -1) {
        cout << color_ << " piece at (" << row_ << ", " << column_ << ") is moving " << (movingUp_ ? "UP" : "DOWN") << endl;
    } else {
        cout << color_ << " piece is not on the board" << endl;
    }
}

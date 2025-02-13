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

// Parameterized Constructor
ChessPiece::ChessPiece(const std::string &color, const int &row, const int &column, const bool &movingUp) : row_(row), column_(column), movingUp_(movingUp) {
    bool valid = true;
    for (char c : color) {
        if (!std::isalpha(c)) {
            valid = false;
            break;
        }
    }
    if (valid) {
        color_ = color;
        for (char &c : color_) c = std::toupper(c);
    } else {
        color_ = "BLACK";
    }
    
    if (row < 0 || row >= BOARD_LENGTH || column < 0 || column >= BOARD_LENGTH) {
        this->row_ = -1;
        this->column_ = -1;
    }
}

// Accessors & Mutators
std::string ChessPiece::getColor() const { return color_; }

bool ChessPiece::setColor(const std::string &color) {
    for (char c : color) {
        if (!std::isalpha(c)) return false;
    }
    color_ = color;
    for (char &c : color_) c = std::toupper(c);
    return true;
}

int ChessPiece::getRow() const { return row_; }

void ChessPiece::setRow(const int &row) {
    if (row < 0 || row >= BOARD_LENGTH) {
        row_ = -1;
        column_ = -1;
    } else {
        row_ = row;
    }
}

int ChessPiece::getColumn() const { return column_; }

void ChessPiece::setColumn(const int &column) {
    if (column < 0 || column >= BOARD_LENGTH) {
        row_ = -1;
        column_ = -1;
    } else {
        column_ = column;
    }
}

bool ChessPiece::isMovingUp() const { return movingUp_; }

void ChessPiece::setMovingUp(const bool &flag) { movingUp_ = flag; }

void ChessPiece::display() const {
    if (row_ != -1 && column_ != -1) {
        std::cout << color_ << " piece at (" << row_ << "," << column_ << ") is moving "
                  << (movingUp_ ? "UP" : "DOWN") << std::endl;
    } else {
        std::cout << color_ << " piece is not on the board" << std::endl;
    }
}

void ChessPiece::runOutput() const {
    display();
}

//Author: Karma Tsewang
//Date: Feb 11 2025
//Defining the rook class.

#include "ChessPiece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include <iostream>

int main() {
    ChessPiece piece("White", 2, 4, true);
    piece.display();

    Pawn pawn("Black", 6, 3, true, true);
    pawn.display();
    std::cout << "Pawn can double jump: " << pawn.canDoubleJump() << std::endl;

    Rook rook("White", 7, 0, false, 2);
    rook.display();
    std::cout << "Rook can castle moves left: " << rook.getCastleMovesLeft() << std::endl;

    return 0;
}

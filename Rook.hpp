//Author: Karma Tsewang
//Date: Feb 11 2025
//Defining the rook class.

#ifndef ROOK_HPP
#define ROOK_HPP

#include "ChessPiece.hpp"

/**
 * @brief Default Constructor. By default, Rooks have 3 available castle moves to make
 * @note Remember to default construct the base-class as well!
 */
class Rook : public ChessPiece {
    private:
        int castle_moves_left_; //number of castle moves left

    public:
        Rook(); //default constructor

        /**
* @brief Parameterized constructor. Rememeber to use the arguments to construct the underlying ChessPiece.
* @param : A const reference to the color of the Rook (a string). Set the color "BLACK" if the provided string contains non-alphabetic characters. 
*     If the string is purely alphabetic, it is converted and stored in uppercase
*     NOTE: We do not supply a default value for color, the first parameter.
*           Notice that if we do, we override the default constructor.
* @param : The 0-indexed row position of the Rook (as a const reference to an integer).
*          Default value -1 if not provided, or if the value provided is outside the
*          board's dimensions, [0, BOARD_LENGTH)
* @param : The 0-indexed column position of the Rook (as a const reference to an integer).
*          Default value -1 if not provided, or if the value provided is outside the
*          board's dimensions, [0, BOARD_LENGTH)
* @param : A flag indicating whether the Rook is moving up on the board, or not (as a const reference to a boolean).
*          Default value false if not provided.
* @param : An integer representing how many castle moves it can make.
*          Default to 3 if no value provided. If a negative value is provided, 0 is used instead.
* @post : The private members are set to the values of the corresponding parameters. 
*   If the provided color parameter is invalid (ie. not alphabetic), it is set to "BLACK"
*   If EITHER of the provided row or col are out-of-bounds, that is between 0 (inclusive)
*      and BOARD_LENGTH (not inclusive), then BOTH are set to -1 (regardless of being in-bounds or not).
* @note Remember to construct the base-class as well using these parameters!
*/
        Rook(const std::string& color, const int& row, const int& column, const bool& movingUp, const int& castle_moves_left);


/**
 * @brief Determines if this rook can castle with the parameter Chess Piece
 *     This rook can castle with another piece if:
 *        1. It has more than 0 castle moves available
 *        2. Both pieces share the same color
 *        3. Both pieces are considered on-the-board (no -1 rows or columns)
 *           and laterally adjacent (ie. they share the same row and their columns differ by at most 1)
 * @param ChessPiece A const reference to chess piece with which the rook may / may not be able to castle with
 * @return True if the rook can castle with the given piece. False otherwise.
 */
        bool canCastle(const ChessPiece &other) const; 
/**
 * @brief Gets the value of the castle_moves_left_
 * @return The integer value stored in castle_moves_left_
 */
        int getCastleMovesLeft() const; 

        void runOutput() const; //runs the output
};

#endif // ROOK_HPP

//Author: Karma Tsewang
//Date: Feb 11 2025
//Defining the chess piece base class.

#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP

#include <string>

class ChessPiece {
    protected:
        std::string color_;  //color of the chess piece
        int row_;   //row of the chess piece
        int column_;    //column of the chess piece
        bool movingUp_; //direction of the chess piece
        static const int BOARD_LENGTH = 8; //size of the chess board

    public:
    /**
 * @brief Default Constructor : All values 
 * Default-initializes all private members.  
 * Booleans are default-initialized to False. 
 * Default color : "BLACK"
 * Default row & columns: -1 (ie. represents that it has not been put on the board yet)
 */
        ChessPiece();//default constructor

        /**
* @brief Parameterized constructor.
* @param : A const reference to the color of the Chess Piece (a string).
*     Set the color "BLACK" if the provided string contains ANY non-alphabetic characters. 
*     If the string is purely alphabetical, it is converted and stored in uppercase
*     NOTE: We DO NOT supply a default value for color, the first parameter.
*           Notice that if we do, we override the default constructor.
* @param : The 0-indexed row position of the Chess Piece (as a const reference to an integer).
*          Default value -1 if not provided.
* @param : The 0-indexed column position of the Chess Piece (as a const reference to an integer).
*          Default value -1.
* @param : A flag indicating whether the Chess Piece is moving up on the board
*          or not (as a const reference to a boolean). Default value False if not provided.
* @post : The private members are set to the values of the corresponding parameters. 
*   If the provided color parameter is invalid (ie. not alphabetic), it is set to "BLACK"
*   If EITHER of the provided row or col are out-of-bounds, where the bounds are between 0 (inclusive)
*      and BOARD_LENGTH (not inclusive), then BOTH are set to -1 (regardless of being in-bounds or not).
*/
        ChessPiece(const std::string& color_, const int& row_ = -1, const int& column_ = -1, const bool& movingUp_ = false);


/**
 * @brief Gets the color of the chess piece.
 * @return std::string - The value stored in color_
 */
        std::string getColor() const; //returns the color of the chess piece

        /**
 * @brief Sets the color of the chess piece.
 * @param color A const string reference, representing the color to set the piece to. 
 *     If the string contains non-alphabetic characters, the value is not set (ie. nothing happens)
 *     If the string is alphabetic, then all characters are converted and stored in uppercase
 * @post The color_ member variable is updated to the parameter value in uppercase
 * @return True if the color was set. False otherwise.
 */
        bool setColor(const std::string& color); //sets the color of the chess piece

    /**
 * @brief Gets the row position of the chess piece.
 * @return The integer value stored in row_
 */
        int getRow() const; //returns the row of the chess piece

        /**
 * @brief Gets the column position of the chess piece.
 * @return The integer value stored in column_
 */
        int getColumn() const; //returns the column of the chess piece

        /**
 * @brief Gets the value of the flag for if a chess piece is moving up
 * @return The boolean value stored in movingUp_
 */
        bool isMovingUp() const; //returns the direction of the chess piece 

/**
 * @brief Sets the row position of the chess piece 
 * @param row A const reference to an integer representing the new row of the piece
 *
 * If the supplied value is outside the board dimensions [0, BOARD_LENGTH), 
 *    the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
 */
        void setRow(const int& row_); //sets the row of the chess piece

        /**
 * @brief Sets the column position of the chess piece 
 * @param row A const reference to an integer representing the new column of the piece
 *
 * If the supplied value is outside the board dimensions [0, BOARD_LENGTH),
 *  the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
 */

        void setColumn(const int& column_); //sets the column of the chess piece

        /**
 * @brief Sets the movingUp flag of the chess piece 
 * @param flag A const reference to an boolean representing whether the piece is now moving up or not
 */
        void setMovingUp(const bool& movingUp_); //sets the direction of the chess piece

/**
 * @brief Displays the chess piece's information in the following format,
 *        if it is considered on the board (ie. its row and col are not -1):
 * <COLOR> piece at (row, col) is moving <UP / DOWN>\n
 * 
 * Otherwise an alternative format is used:
 * <COLOR> piece is not on the board\n
 * @note "\n" just means endline in this case. Please use "std::endl," don't print out the text "\n".
 * Example output 1:
   BLACK piece at (2,4) is moving UP
   Example output 2:
   WHITE piece is not on the board
 */
        void display() const; //displays the chess piece
        void runOutput() const; //runs the output
};

#endif // CHESSPIECE_HPP

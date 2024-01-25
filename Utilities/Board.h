/*
    Board

    Represents an 8x8 chessboard.
*/

#ifndef BOARD_H
#define BOARD_H

#define DIMENSION 8

#include <ostream>

#include "Square.h"

using namespace std;

class Board 
{
 public:

    ~Board();

    /**
    * Gets the board.
    *
    * @return The chessboard.
    */
    static Board* GetBoard();

    /**
    * Gets the specific square on the board.
    *
    * @param x, y - position of the board
    * @return The square of interest.
    */
    Square* GetSquareAt(int x, int y) const;

    /**
    * Determines if the path between two squares is clear vertical.
    *
    * @param from - first square
    * @param to - second square
    * @return If the given vertical path is clear vertical.
    */
    bool IsClearVertical(Square& from, Square& to) const;

    /**
    * Determines if the path between two squares is clear horizontal.
    *
    * @param from - first square
    * @param to - second square
    * @return If the horizontal path is clear horizontal.
    */
    bool IsClearHorizontal(Square& from, Square& to) const;

    /**
    * Determines if the path between two squares is clear diagonal.
    *
    * @param from - first square
    * @param to - second square
    * @return If the path is a clear diagonal.
    */
    bool IsClearDiagonal(Square& from, Square& to) const;
    
    /**
     * Determines if the square is located on an ending row of the board
     *
     * @param square the square to check
     * @return if the square is on an end row
     */
    bool IsEndRow(Square& location) const;

    /**
    * Displays the board.
    *
    * @param outputStream - the output stream
    */
    void Display(ostream& outputStream) const;

 private:
    
    Board();

    static Board* board;
    Square* squares[DIMENSION][DIMENSION];
};

#endif
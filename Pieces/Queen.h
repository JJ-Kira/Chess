/*
    Queen
 
    Represents a queen chesspiece.
*/

#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>

#include "Piece.h"
#include "../Utilities/Square.h"

using namespace std;

class Queen : public Piece
{
 public:
    
    /**
    * Creates a queen.
    *
    * @param isWhite - if the color of the piece is white
    */
    Queen(bool isWhite);
    
    /**
     * Default destructor
     */
    ~Queen();

    /**
    * Gets the point value of the piece.
    *
    * @return Piece's value.
    */
    int Value() const;

    /**
    * Determines if the piece can move to a given square
    without breaking any rules.
    *
    * @param investigatedPosition - the square to check the move to
    * @return If the move is legal.
    */
    bool CanMoveTo(Square& investigatedPosition) const;
};

#endif
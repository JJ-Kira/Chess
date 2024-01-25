/*
    Knight
 
    Represents a knight chess piece.
*/

#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>

#include "Piece.h"
#include "../Utilities/Square.h"

using namespace std;

class Knight : public Piece
{
 public:
    
    /**
    * Creates a knight.
    *
    * @param isWhite - if the color of the piece is white
    */
    Knight(bool isWhite);
    
    ~Knight();

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
    
    /**
     * Displays the piece.
     */
    void Display() const;
};

#endif

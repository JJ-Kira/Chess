/*
    King
 
    Represents a king chesspiece.
*/

#ifndef KING_H
#define KING_H

#include <iostream>

#include "RestrictedPiece.h"

using namespace std;

class King : public RestrictedPiece
{
 public:

   /**
    * Creates a king.
    *
    * @param isWhite - if the color of the piece is white
    */
    King(bool isWhite);
    
    ~King();

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

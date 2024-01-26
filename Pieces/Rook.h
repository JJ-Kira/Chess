/*
    Rook

    This class represents a rook chesspiece.

*/

#ifndef ROOK_H
#define ROOK_H

#include <iostream>

#include "RestrictedPiece.h"
#include "../Utilities/Square.h"

using namespace std;

class Rook : public RestrictedPiece
{
 public:
    
    /**
    * Creates a rook.
    *
    * @param isWhite - if the color of the piece is white
    */
    Rook(bool isWhite);
    
    ~Rook();

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

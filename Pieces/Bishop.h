/*
    Bishop

    This class represents a bishop chesspiece.
*/

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>

#include "Piece.h"
#include "../Utilities/square.h"

using namespace std;

class Bishop : public Piece
{
 public:
    
    /**
    * Creates a bishop.
    *
    * @param isWhite - if the color of the piece is white
    */
    Bishop(bool isWhite);
    
    ~Bishop();

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

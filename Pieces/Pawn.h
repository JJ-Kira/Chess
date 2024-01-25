/*
    Pawn
 
    This class represents a pawn chesspiece.
*/

#ifndef PAWN_H
#define PAWN_H

#include <iostream>

#include "RestrictedPiece.h"
#include "../Utilities/Square.h"

using namespace std;

class Pawn : public RestrictedPiece
{
 public:
    
    /**
    * Creates a pawn.
    *
    * @param isWhite - if the color of the piece is white
    */
    Pawn(bool isWhite);
    
    ~Pawn();

    /**
    * Sets the square the piece is located on.
    *
    * @param newLocation - the square
    */
    virtual void SetLocation(Square* newLocation);

    /**
    * Gets the point value of the piece.
    *
    * @return Piece's value.
    */
    int Value() const;
    
    /**
    * Moves the piece to the square, making sure that
    * the move is in accordance with the rules.
    *
    * @param player - the piece on the square
    * @param destinationSquare - square the piece is to be placed on
    * @return If the move was successful.
    */
    bool Move(Player& player, Square& destinationSquare);

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
   
 private:

    Piece* delegate;
};

#endif

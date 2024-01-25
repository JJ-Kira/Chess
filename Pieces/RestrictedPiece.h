/*
    RestrictedPiece
 
    Represents a chesspiece that knows whether 
    it has been moved previously.
*/

#ifndef RESTRICTED_H
#define RESTRICTED_H

#include "Piece.h"

class Player;

using namespace std;

class RestrictedPiece : public Piece
{
 public:
    
    /**
    * Creates a Restricted Piece.
    *
    * @param isWhite - if piece is white
    */
    RestrictedPiece(bool isWhite);
    
    virtual ~RestrictedPiece();

    /**
    * Moves the piece to the square, making sure that
    * the move is in accordance with the rules.
    *
    * @param player - the piece on the square
    * @param destinationSquare - square the piece is to be placed on
    * @return If the move was successful.
    */
    virtual bool Move(Player& player, Square& destinationSquare);

    /**
    * Determines if the piece has been previously moved.
    *
    * @return If the piece was moved.
    */
    bool WasMoved() const;

 private:
   
    bool moved;
};

#endif
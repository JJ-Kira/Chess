/*
    Piece
 
    This class represents a chesspiece.
*/

#ifndef PIECE_H
#define PIECE_H

#include <ostream>

#include "../Utilities/Board.h"
#include "../Utilities/Square.h"
class Player;

using namespace std;

class Piece 
{
 public:
   
    /**
    * Creates a Piece
    *
    * @param isWhite - if the color of the piece is white
    */
    Piece(bool isWhite);
    
    virtual ~Piece();

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
    virtual int Value() const = 0;

    /**
    * Determines if the piece is white.
    *
    * @return If piece is white.
    */
    bool IsWhite() const;

    /**
     * Gets the piece's color.
     *
     * @return Piece's color.
     */
    int Color() const;    
    
    /**
    * Displays the piece.
    */
    void Display();
    //virtual void Display() const = 0;   

    /**
    * Determines if the piece can move to a given square
    * based on the geometry of the move without breaking
    * the rules.
    *
    * @param investigatedPosition - the square to check the move to
    * @return If the move is legal.
    */
    virtual bool CanMoveTo(Square& investigatedPosition) const = 0;

    /**
    * Determines if the piece is located on a square.
    *
    * @return If on square.
    */
    bool IsOnSquare() const;

    /**
    * Gets the piece's location.
    *
    * @return The square the piece is located on.
    */
    Square* Position() const;

 protected:

    bool isWhite;
    int color;
    wchar_t symbol[3];
    
 private:

    Square* square;
};


#endif
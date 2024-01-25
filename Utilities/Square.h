/*
    Square
    
    Represents a square on a game board.
*/

#ifndef SQUARE_H
#define SQUARE_H

class Piece;

using namespace std;

class Square 
{
 public:
   
    /**
    * Creates a Square.
    *
    * @param x, y - location of the square on the board
    */
    Square(int x, int y);

    ~Square();
    
    /**
    * Makes the square occupied by a given piece.
    *
    * @param piece - the piece to be set on the square
    */
    void SetOccupiedByPiece(Piece* piece);

    /**
    * Gets the s position of the square.
    *
    * @return The x position of the square (int).
    */
    int GetX() const;

    /**
    * Gets the y position of the square.
    *
    * @return The y position of the square.
    */
    int GetY() const;

    /**
    * Determines if the square is occupied by a piece.
    *
    * @return If occupied.
    */
    bool Occupied() const;   

    /**
    * Gets the piece occupying the square.
    *
    * @return the piece
    */
    Piece* GetOccupyingPiece() const;


 private:
    int x;
    int y;
    Piece* piece;
};

#endif
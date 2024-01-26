#include <string>

#include "Piece.h"
#include "../Utilities/Player.h"

Piece::Piece(bool isWhite) : isWhite(isWhite), square(NULL)
{
}

Piece::~Piece()
{
}

bool Piece::Move(Player& player, Square& destinationSquare)
{
    bool moveValidity = false;
    Piece* pieceToCapture = NULL;
    Square* currentSquare = square;
    
    // check if owner is making the move
    if(isWhite == player.IsWhite())
    {
        // check geometrical validity
        if(CanMoveTo(destinationSquare))
        {
            if(destinationSquare.Occupied())
            {
                pieceToCapture = destinationSquare.GetOccupyingPiece();
                
                if(pieceToCapture->IsWhite() != player.IsWhite())
                {
                    moveValidity = true;
                }
            }
            else 
            {
                moveValidity = true;
            }

            if(moveValidity)
            {
                if(pieceToCapture)
                {
                    pieceToCapture->SetLocation(NULL);
                } 
                
                // unset current square's occupant
                square->SetOccupiedByPiece(NULL);
                
                // set piece's new square
                square = &destinationSquare;
                
                // set as new square's occupant
                square->SetOccupiedByPiece(this);
                
                // check if the move leaves player's king in check
                if(player.InCheck())
                {
                    // if in check, move is invalid
                    moveValidity = false;
                    
                    // undo the move
                    // reset this piece's location
                    square = currentSquare;
                    
                    // update the square's occupant
                    square->SetOccupiedByPiece(this);
                    
                    // reset the other square's occupant with opponent's piece or NULL
                    destinationSquare.SetOccupiedByPiece(pieceToCapture);
                    
                    if(pieceToCapture)
                    {
                        pieceToCapture->SetLocation(&destinationSquare);
                    }
                }
                else 
                {
                    if(pieceToCapture)
                    {
                        player.Capture(pieceToCapture);
                    } 
                }
            }
        }
    }
    
    return moveValidity;
}

void Piece::Display()
{
    //cout << symbol;
    HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD n;
    WriteConsoleW(cons, symbol, wcslen(symbol), &n, NULL);
}

void Piece::SetLocation(Square* newLocation)
{
    square = newLocation;
}

bool Piece::IsWhite() const
{
    return isWhite;
}

int Piece::Color() const
{
    return color;
}

bool Piece::IsOnSquare() const
{
    return square;
}

Square* Piece::Position() const
{
    return square;
}
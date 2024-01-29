#include "King.h"

King::King(bool isWhite) : RestrictedPiece(isWhite)
{
    //symbol = isWhite ? L"\u2654" : L"\u265A";
    wcsncpy_s(symbol, L"\u265A", 2); // Copying the Unicode character to p
    symbol[2] = L'\0'; // Ensuring null termination
}

King::~King()
{
}

int King::Value() const
{
    return 0;
}

bool King::CanMoveTo(Square& investigatedPosition) const
{
    bool validMove = false;
    int translationX = investigatedPosition.GetX() - this->Position()->GetX();
    int translationY = investigatedPosition.GetY() - this->Position()->GetY();
    
    // valid move - moving 1 square forward/backward
    if(abs(translationY) == 1 && translationX == 0)
    {
        validMove = true;
    }
    
    // valid move - moving 1 square sideways
    else if(abs(translationX) == 1 && translationY == 0)
    {
        validMove = true;
    }
    
    // valid move - moving 1 square diagonally
    else if(abs(translationX) == 1 && abs(translationY) == 1)
    {
        validMove = true;
    }
    
    return validMove;
}
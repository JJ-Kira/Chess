#include "Knight.h"

Knight::Knight(bool isWhite) : Piece(isWhite)
{
    //symbol = isWhite ? L"\u2658" : L"\u265E";
    wcsncpy_s(symbol, isWhite ? L"\u2658" : L"\u265E", 2); // Copying the Unicode character to p
    symbol[2] = L'\0'; // Ensuring null termination
}

Knight::~Knight()
{
}

int Knight::Value() const
{
    return 3;
}

bool Knight::CanMoveTo(Square& investigatedPosition) const
{
    bool validMove = false;
    int translationX = investigatedPosition.GetX() - this->Position()->GetX();
    int translationY = investigatedPosition.GetY() - this->Position()->GetY();
    
    // valid move - moving 1 square forward/backward and 2 squares sideways
    if(abs(translationY) == 1 && abs(translationX) == 2)
    {
        validMove = true;
    }
    
    // valid move - moving 1 square sideways and 2 squares forward/backward
    else if(abs(translationX) == 1 && abs(translationY) == 2)
    {
        validMove = true;
    }
    
    return validMove;
}


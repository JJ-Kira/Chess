#include "Rook.h"

Rook::Rook(bool isWhite) : RestrictedPiece(isWhite)
{
    //symbol = isWhite ? L"\u2656" : L"\u265C";
    wcsncpy_s(symbol, L"\u265C", 2); // Copying the Unicode character to p
    symbol[2] = L'\0'; // Ensuring null termination
}

Rook::~Rook()
{
}

int Rook::Value() const
{
    return 5;
}

bool Rook::CanMoveTo(Square& investigatedPosition) const
{
    bool validMove = false;
    
    // valid move - moving on a clear vertical
    if(Board::GetBoard()->IsClearVertical(*(this->Position()), investigatedPosition))
    {
        validMove = true;
    }
    
    // valid move - moving on a clear horizontal
    else if(Board::GetBoard()->IsClearHorizontal(*(this->Position()), investigatedPosition))
    {
        validMove = true;
    }
    
    return validMove;
}
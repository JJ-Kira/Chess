#include "Rook.h"

Rook::Rook(bool isWhite) : RestrictedPiece(isWhite)
{
    symbol = isWhite ? '\u2656' : '\u265C';
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
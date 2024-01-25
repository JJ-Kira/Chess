#include "Queen.h"

Queen::Queen(bool isWhite) : Piece(isWhite)
{
    symbol = isWhite ? '\u2655' : '\u265B';
}

Queen::~Queen()
{
}

int Queen::Value() const
{
    return 9;
}

bool Queen::CanMoveTo(Square& investigatedPosition) const
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
    
    // valid move - moving on a clear diagonal
    else if(Board::GetBoard()->IsClearDiagonal(*(this->Position()), investigatedPosition))
    {
        validMove = true;
    }
    
    
    return validMove;
}
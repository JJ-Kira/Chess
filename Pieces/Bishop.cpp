#include "Bishop.h"

Bishop::Bishop(bool isWhite) : Piece(isWhite)
{
    symbol = isWhite ? '\u2657' : '\u265D';
}

Bishop::~Bishop()
{
}

int Bishop::Value() const
{
    return 3;
}

bool Bishop::CanMoveTo(Square& investigatedPosition) const
{
    bool validMove = false;
    
    // valid move - moving on a clear diagonal
    if(Board::GetBoard()->IsClearDiagonal(*(this->Position()), investigatedPosition))
    {
        validMove = true;
    }
    
    return validMove;
}
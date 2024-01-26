#include "Bishop.h"

Bishop::Bishop(bool isWhite) : Piece(isWhite)
{
    //symbol = isWhite ? L"\u2657" : L"\u265D";
    wcsncpy_s(symbol, isWhite ? L"\u2657" : L"\u265D", 2); // Copying the Unicode character to p
    symbol[2] = L'\0'; // Ensuring null termination
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
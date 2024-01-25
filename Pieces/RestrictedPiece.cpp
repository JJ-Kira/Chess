#include "../Utilities/Player.h"
#include "RestrictedPiece.h"

RestrictedPiece::RestrictedPiece(bool isWhite) : Piece(isWhite)
{
    moved = false;
}
    
RestrictedPiece::~RestrictedPiece()
{
}

bool RestrictedPiece::Move(Player& byPlayer, Square& to)
{
    bool validMove = Piece::Move(byPlayer, to);
    
    if(validMove && !moved)
    {
        moved = true;
    }
    
    return validMove;
}

bool RestrictedPiece::WasMoved() const
{
    return moved;
}
#include "../Pieces/Piece.h"
#include "square.h"

Square::Square(int x, int y) : x(x), y(y), piece(NULL)
{
}

Square::~Square()
{
}

void Square::SetOccupiedByPiece(Piece* aPiece)
{
    piece = aPiece;
}

int Square::GetX() const
{
    return x;
}

int Square::GetY() const
{
    return y;
}

bool Square::Occupied() const
{
    return piece;
}

Piece* Square::GetOccupyingPiece() const
{
    return piece;
}
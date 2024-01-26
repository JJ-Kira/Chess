#include "Board.h"
#include "../Pieces/Piece.h"

Board::Board()
{
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            squares[i][j] = new Square(i, j);
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            delete[] squares[i][j];
        }
        delete[] squares[i];
    }
    delete[] squares;
}

Board* Board::GetBoard()
{
    if (!board)
        board = new Board();
    return board;
}

Square* Board::GetSquareAt(int x, int y) const
{
    return squares[x][y];
}

bool Board::IsClearVertical(Square& from, Square& to) const
{
    Square* start = NULL;
    Square* end = NULL;
    bool valid = true;
    
    if(from.GetY() <= to.GetY())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }
    
    if(start->GetX() != end->GetX())
    {
        valid = false;
    }
    else 
    {
        for(int i = start->GetY() + 1; i < end->GetY(); i++)
        {
            if(GetSquareAt(start->GetX(), i)->Occupied())
            {
                valid = false;
            }
        } 
    }
    
    return valid;
}

bool Board::IsClearHorizontal(Square& from, Square& to) const
{
    Square* start = NULL;
    Square* end = NULL;
    bool valid = true;
    
    if(from.GetX() <= to.GetX())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }
    
    if(start->GetY() != end->GetY())
    {
        valid = false;
    }
    else 
    {
        for(int i = start->GetX() + 1; i < end->GetX(); i++)
        {
            if(GetSquareAt(i, start->GetY())->Occupied())
            {
                valid = false;
            }
        } 
    }
    
    return valid;
}

bool Board::IsClearDiagonal(Square& from, Square& to) const
{
    bool valid = true;
    int translationX = to.GetX() - from.GetX();
    int translationY = to.GetY() - from.GetY();
    int xDir = 1;
    int yDir = 1;
    
    if(translationX < 0)
    {
        xDir = -1;
    }
    
    if(translationY < 0)
    {
        yDir = -1;
    }
    
    if(abs(translationX) != abs(translationY))
    {
        valid = false;
    }
    else 
    {
        for(int i = 1; i < abs(translationX); i++)
        {
            if(GetSquareAt(from.GetX() + (i * xDir), from.GetY() + (i * yDir))->Occupied())
            {
                valid = false;
            }
        }
    }
    
    return valid;
}

bool Board::IsEndRow(Square& location) const
{
    return (location.GetY() == 0 || location.GetY() == (DIMENSION - 1));
}

void Board::Display(ostream& outStream) const
{
    outStream << endl << "   A  B  C  D  E  F  G  H" << endl;
    outStream << " -------------------------" << endl;
    for (int y = DIMENSION - 1; y >= 0; y--) // black on top, white on bottom
    {
        outStream << y + 1;
        for (int x = 0; x < DIMENSION; x++)
        {
            outStream << "|";
            if(squares[x][y]->Occupied())
                squares[x][y]->GetOccupyingPiece()->Display();
            else
                outStream << "  ";
        }
        outStream << "|" << y + 1 << endl << " -------------------------" << endl;
    }
    outStream << "   A  B  C  D  E  F  G  H" << endl << endl;
}

Board* Board::board = NULL;
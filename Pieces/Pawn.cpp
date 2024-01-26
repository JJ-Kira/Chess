#include <windows.h>

#include "Piece.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "../Utilities/Board.h"

Pawn::Pawn(bool isWhite) : RestrictedPiece(isWhite), delegate(NULL)
{
    //symbol = isWhite ? L"\u2659" : L"\u265F";
    wcsncpy_s(symbol, isWhite ? L"\u2659" : L"\u265F", 2); // Copying the Unicode character to p
    symbol[2] = L'\0'; // Ensuring null termination
}

Pawn::~Pawn()
{
    if(delegate)
        delete delegate;
}

void Pawn::SetLocation(Square* investigatedPosition)
{
    Piece::SetLocation(investigatedPosition);
}

int Pawn::Value() const
{
    return 1;
}

bool Pawn::Move(Player& byPlayer, Square& to)
{
    bool valid = false;
    
    // if the delegate was set, it means the pawn has been promoted
    if(delegate)
    {
        // use the delegate piece's movement rules to determine validity of the move
        valid = delegate->Move(byPlayer, to);
        
        if(valid)
        {
            // unset current square's occupant
            Position()->SetOccupiedByPiece(NULL);
            
            // set new location
            SetLocation(&to);
            
            // set as new square's occupant
            Position()->SetOccupiedByPiece(this);
        }
    }
    else
    {
        // move normally as a pawn
        valid = RestrictedPiece::Move(byPlayer, to);

        // promotion
        if (valid)
        {
            if (Board::GetBoard()->IsEndRow(*Position()))
            {
                char choice;
                cout << "Choose the chesspiece to promote to: " << endl;
                cout << "Q - queen" << endl;
                cout << "B - bishop" << endl;
                cout << "K - knight" << endl;
                cout << "R - rook" << endl;
                cout << "Your choice of promotion: " << endl;
                while (!delegate) {
                    cin >> choice;
                    switch (choice)
                    {
                    case 'Q':
                    case 'q':
                        delegate = new Queen(IsWhite());
                        break;
                    case 'B':
                    case 'b':
                        delegate = new Bishop(IsWhite());
                        break;
                    case 'K':
                    case 'k':
                        delegate = new Knight(IsWhite());
                        break;
                    case 'R':
                    case 'r':
                        delegate = new Rook(IsWhite());
                        break;
                    }
                    delegate->SetLocation(Position());
                }
            }
        }
    }
    return valid;
}

bool Pawn::CanMoveTo(Square& location) const
{
    bool validMove = false;
    int translationX = location.GetX() - this->Position()->GetX();
    int translationY = location.GetY() - this->Position()->GetY();
    
    // if promoted
    if(delegate)
    {
        validMove = delegate->CanMoveTo(location);
    }
    else 
    {
        if(!IsWhite())
        {
            translationX *= -1;
            translationY *= -1;
        }
        
        // valid move - 1 square forward to unoccupied square
        if(!location.Occupied() && translationY == 1 && translationX == 0)
            validMove = true;
        // valid move - hasn't been moved yet and moving 2 squares forward to an unoccupied square along a clear vertical
        else if(!WasMoved() && translationY == 2 && translationX == 0 && Board::GetBoard()->IsClearVertical(*(this->Position()), location))
            validMove = true;
        // valid move - capturing a piece on adjacent diagonal
        else if(location.Occupied() && translationY == 1 && (translationX == 1 || translationX == -1))
            validMove = true;       
    }
    return validMove;
}

void Pawn::Display()
{
    if (delegate)
        delegate->Display();
    else
    {
        HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD n;
        WriteConsoleW(cons, symbol, wcslen(symbol), &n, NULL);
    }
}
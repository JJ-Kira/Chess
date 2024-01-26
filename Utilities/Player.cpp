#include <iostream>
#include <string>

#include "Player.h"
#include "Board.h"
#include "ChessGame.h"

#define X_MIN 'A'
#define X_MAX 'H'
#define Y_MIN '1'
#define Y_MAX '8'

Player::Player(string name, bool isWhite, King& myKing, set<Piece*>& myPieces) :
name(name), isWhite(isWhite), ownedPieces(myPieces), king(myKing)
{
    color = isWhite ? 9 : 12;
}

Player::~Player()
{
}

bool Player::MakeAMove()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    string badInput; // handling invalid input
    string currentSquare =  " ";
    string newSquare = "  ";
    int currentX;
    int currentY;
    int newX;
    int newY;
    
    if(InCheck())
    {
        cout << name << " is in check!" << endl;
    }
    
    // player input
    // a2 a4 - move piece currently positioned on square A2 to square A4
    cout << "Player " << name << ", enter move (format: A2 A4): ";
    cin >> currentSquare >> newSquare;
    
    while(currentSquare.length() != 2 || newSquare.length() != 2 ||
          toupper(currentSquare.at(0)) < X_MIN || toupper(currentSquare.at(0)) > X_MAX ||
          toupper(newSquare.at(0)) < X_MIN || toupper(newSquare.at(0)) > X_MAX ||
          toupper(currentSquare.at(1)) < Y_MIN || toupper(currentSquare.at(1)) > Y_MAX ||
          toupper(newSquare.at(1)) < Y_MIN || toupper(newSquare.at(1)) > Y_MAX ||
          !(Board::GetBoard()->GetSquareAt(toupper(currentSquare.at(0)) - X_MIN, toupper(currentSquare.at(1)) - Y_MIN)->Occupied()))
    {
        cerr << "Invalid move. Try again." << endl;
        cin.clear();
        getline(cin, badInput); // take bad input off the stream and ignore it
        cout << "Player " << name << ", enter move (format: A2 A4): ";
        cin >> currentSquare >> newSquare;
    }
    
    // translate algebraic notation input into board coordinates
    currentX = toupper(currentSquare.at(0)) - X_MIN;
    currentY = toupper(currentSquare.at(1)) - Y_MIN;
    newX = toupper(newSquare.at(0)) - X_MIN;
    newY = toupper(newSquare.at(1)) - Y_MIN;
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    // make the move
    return Board::GetBoard()->GetSquareAt(currentX, currentY)->GetOccupyingPiece()->Move(*this, *(Board::GetBoard()->GetSquareAt(newX, newY)));
}

bool Player::InCheck()
{
    bool check = false;
    
    // iterate over the opponent's set
    for (set<Piece*>::iterator itr = ChessGame::GetPlayersOpponent(*this)->GetSet()->begin(); 
         itr != ChessGame::GetPlayersOpponent(*this)->GetSet()->end(); ++itr)
    {
        // if a piece still on the board can move to my king's square
        if (((Piece*)*itr)->Position() && 
            ((Piece*)*itr)->CanMoveTo(*(GetKing()->Position())))
        {
            // player in check
            check = true;
        }
    }
    
    return check;
}

void Player::Capture(Piece* aPiece)
{
    aPiece->SetLocation(NULL);
    capturedPieces.insert(aPiece);
}

string Player::GetName() const
{
    return name;
}

bool Player::IsWhite() const
{
    return isWhite;
}

int Player::score() const
{
    int score = 0;
    
    for (set<Piece*>::iterator itr = capturedPieces.begin(); itr != capturedPieces.end(); ++itr)
    {
        score += ((Piece*)*itr)->Value();
    }
    
    return score;
}

set<Piece*>* Player::GetSet() const
{
    return &ownedPieces;
}

King* Player::GetKing() const
{
    return &king;
}
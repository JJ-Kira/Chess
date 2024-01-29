#include "ChessGame.h"
#include "Square.h"
#include "../Pieces/Queen.h"
#include "../Pieces/Bishop.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Rook.h"
#include "../Pieces/Pawn.h"
#include "../Pieces/King.h"
    
ChessGame::ChessGame()
{
}

ChessGame::~ChessGame()
{
    for (set<Piece*>::iterator itr = whitePieces.begin();
         itr != whitePieces.end(); ++itr)
    {
        delete *itr;
    }
    whitePieces.clear();
    for (set<Piece*>::iterator itr = blackPieces.begin();
         itr != blackPieces.end(); ++itr)
    {
        delete *itr;
    }
    blackPieces.clear();
    
    delete &player1;
    delete &player2;

    LPCWSTR fontPath = L"Fonts/DejaVu Sans Mono for Powerline.ttf";
    if (RemoveFontResourceEx(fontPath, FR_NOT_ENUM, 0) == 0) {
        std::cerr << "Failed to remove font." << std::endl;
    }
}

void MaximizeWindow()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, 800, 800, TRUE);
}

void SetFont()
{
    LPCWSTR fontPath = L"Fonts/DejaVu Sans Mono for Powerline.ttf";

    if (AddFontResourceEx(fontPath, FR_NOT_ENUM, 0) == 0) {
        std::cerr << "Failed to load font." << std::endl;
    }

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0; // Width of each character in the font
    cfi.dwFontSize.Y = 32; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"DejaVu Sans Mono for Powerline");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    if (RemoveFontResourceEx(fontPath, FR_NOT_ENUM, 0) == 0) {
        std::cerr << "Failed to remove font." << std::endl;
    }
}

void ChessGame::Initialize()
{
    // set up console visuals
    SetFont();
    MaximizeWindow();

    // set up the game
    Piece* piece;
    King* king;
    Square* square;
    
    whitePieces = *(new set<Piece*>);
    blackPieces = *(new set<Piece*>);
    
    piece = new Queen(true);
    square = Board::GetBoard()->GetSquareAt(3, 0);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    whitePieces.insert(piece);
    piece = new Queen(false);
    square = Board::GetBoard()->GetSquareAt(3, 7);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    blackPieces.insert(piece);
    
    piece = new Bishop(true);
    square = Board::GetBoard()->GetSquareAt(2, 0);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    whitePieces.insert(piece);
    piece = new Bishop(false);
    square = Board::GetBoard()->GetSquareAt(2, 7);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    blackPieces.insert(piece);
    piece = new Bishop(true);
    square = Board::GetBoard()->GetSquareAt(5, 0);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    whitePieces.insert(piece);
    piece = new Bishop(false);
    square = Board::GetBoard()->GetSquareAt(5, 7);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    blackPieces.insert(piece);
    
    piece = new Knight(true);
    square = Board::GetBoard()->GetSquareAt(1, 0);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    whitePieces.insert(piece);
    piece = new Knight(false);
    square = Board::GetBoard()->GetSquareAt(1, 7);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    blackPieces.insert(piece);
    piece = new Knight(true);
    square = Board::GetBoard()->GetSquareAt(6, 0);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    whitePieces.insert(piece);
    piece = new Knight(false);
    square = Board::GetBoard()->GetSquareAt(6, 7);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    blackPieces.insert(piece);
    
    piece = new Rook(true);
    square = Board::GetBoard()->GetSquareAt(0, 0);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    whitePieces.insert(piece);
    piece = new Rook(false);
    square = Board::GetBoard()->GetSquareAt(0, 7);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    blackPieces.insert(piece);
    piece = new Rook(true);
    square = Board::GetBoard()->GetSquareAt(7, 0);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    whitePieces.insert(piece);
    piece = new Rook(false);
    square = Board::GetBoard()->GetSquareAt(7, 7);
    square->SetOccupiedByPiece(piece);
    piece->SetLocation(square);
    blackPieces.insert(piece);
    
    for (int i = 0; i < 8; i++)
    {
        piece = new Pawn(true);
        square = Board::GetBoard()->GetSquareAt(i, 1);
        square->SetOccupiedByPiece(piece);
        piece->SetLocation(square);
        whitePieces.insert(piece);
        piece = new Pawn(false);
        square = Board::GetBoard()->GetSquareAt(i, 6);
        square->SetOccupiedByPiece(piece);
        piece->SetLocation(square);
        blackPieces.insert(piece);
    }
    
    king = new King(true);
    square = Board::GetBoard()->GetSquareAt(4, 0);
    square->SetOccupiedByPiece(king);
    king->SetLocation(square);
    whitePieces.insert(king);
    
    player1 = new Player("White", true, *king, whitePieces);
                     
    king = new King(false);
    square = Board::GetBoard()->GetSquareAt(4, 7);
    square->SetOccupiedByPiece(king);
    king->SetLocation(square);
    blackPieces.insert(king);
    
    player2 = new Player("Black", false, *king, blackPieces);
    
    nextPlayer = player2;
}

void ChessGame::Start()
{
    Board::GetBoard()->Display(cout);
    Player* currentPlayer = NULL;

    bool endGame = false;
    while (!endGame)
    {
        currentPlayer = ChessGame::GetNextPlayer();
        while (!currentPlayer->MakeAMove(&endGame))
        {
            cerr << "Invalid move... Try again." << endl;
        }
        Board::GetBoard()->Display(cout);
    }
}
    
Player* ChessGame::GetNextPlayer()
{
    nextPlayer = GetPlayersOpponent(*nextPlayer);
    return nextPlayer;
}
    
Player* ChessGame::GetPlayersOpponent(Player& player)
{
    Player* opponent;
    
    if(player.GetName() == player1->GetName())
        opponent = player2;
    else 
        opponent = player1;

    return opponent;
}

Player* ChessGame::player1 = NULL;
Player* ChessGame::player2 = NULL;
Player* ChessGame::nextPlayer = NULL;
set<Piece*> ChessGame::whitePieces;
set<Piece*> ChessGame::blackPieces;
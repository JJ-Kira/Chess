#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "Utilities/Board.h"
#include "Utilities/ChessGame.h"

int main(int argc, char* const argv[])
{
    HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
    wchar_t p[] = L"\u265B";
    DWORD n;
    WriteConsoleW(cons, p, wcslen(p), &n, NULL);

    Player* currentPlayer = NULL;

    ChessGame::Initialize();
    Board::GetBoard()->Display(cout);

    while (true)
    {
        currentPlayer = ChessGame::GetNextPlayer();
        while (!currentPlayer->MakeAMove())
        {
            cerr << "Invalid move... Try again." << endl;
        }
        Board::GetBoard()->Display(cout);
    }

    return 0;
}
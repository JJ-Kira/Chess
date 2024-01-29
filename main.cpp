#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include "resource.h"
#include "Utilities/Board.h"
#include "Utilities/ChessGame.h"

void MaximizeWindow()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, 900, 900, TRUE); // 800 width, 100 height
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
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 36;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"DejaVu Sans Mono for Powerline"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

int main(int argc, char* const argv[])
{
    Player* currentPlayer = NULL;

    SetFont();
    MaximizeWindow();

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
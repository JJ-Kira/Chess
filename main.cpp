#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include "resource.h"
#include "Utilities/Board.h"
#include "Utilities/ChessGame.h"

int main(int argc, char* const argv[])
{
     ChessGame::Initialize();
     ChessGame::Start();

    return 0;
}
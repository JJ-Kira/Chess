/*
    Game

    Represents a game of chess.
*/

#ifndef GAME_H
#define GAME_H

#include <set>
#include <iostream>

#include "Board.h"
#include "Player.h"
#include "../Pieces/Piece.h"

using namespace std;

class ChessGame 
{
 public:

     ChessGame();

    ~ChessGame();

    /**
     * Sets up a new match of chess.
     *
     */
    static void Initialize();

    /**
     * Starts the prepared game.
     *
     */
    static void Start();

    /**
    * Gets the player whose turn is next.
    *
    * @return The player to play next.
    */
    static Player* GetNextPlayer();

    /**
    * Gets the given player's opponent.
    *
    * @param player - the player whose oppenent is to be returned
    * @return The opponent.
    */
    static Player* GetPlayersOpponent(Player& player);

 private:

    static Player *player1, *player2, *nextPlayer;
    static set<Piece*> whitePieces, blackPieces;
};

#endif

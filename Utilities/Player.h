/*
    Player

    Represents a chess player.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <set>

#include "../Pieces/Piece.h"
#include "../Pieces/King.h"

using namespace std;

class Player 
{
public:
    
    /**
     * Creates a Player.
     *
     * @param name - name of the player
     * @param isWhite - whether is playing white or black
     * @param playersKing - the king of the player
     * @param playersPieces - the player's set
     */
    Player(string name, bool isWhite, King& playersKing, set<Piece*>& myPieces);
    
    ~Player();
    
    /**
     * Makes a move.
     *
     * @return Whether a move has been performed successfully.
     */
    bool MakeAMove();
    
    /**
     * Checks if the player is currently in check.
     *
     * @return If in check.
     */
    bool InCheck();
    
    /**
     * Captures a piece.
     *
     * @param aPiece the piece to be captured
     */
    void Capture(Piece* piece);
    
    /**
     * Gets the player's name.
     *
     * @return Player's name.
     */
    string GetName() const;
    
    /**
     * Determines if this is a white player.
     *
     * @return If is white.
     */
    bool IsWhite() const;
    
    /**
     * Gets the total score of the pieces captured by the player.
     *
     * @return Player's score (int).
     */
    int score() const;   
    
    /**
     * Gets the player's set.
     *
     * @return The set.
     */
    set<Piece*>* GetSet() const;
    
    /**
     * Gets this player's king.
     *
     * @return The king.
     */
    King* GetKing() const;
    
    
private:

    string name;
    bool isWhite;
    set<Piece*>& ownedPieces;
    set<Piece*> capturedPieces;
    King& king;
};

#endif
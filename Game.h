#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Board.h"
#include "Player.h"
#include <vector>

class Game {
    public:
     Game();

     void setup();
     void Start();

    private:
     Deck deck;
     Board board;
     Player player;
     Player opponent;
     bool isPlayersTurn;
};

#endif // GAME_H
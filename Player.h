#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"
#include "Board.h"
#include <iostream>
#include <vector>

class Player {

    public:
     Player(const string& playername);
     string getName() const;
     void drawCards(Deck& deck);
     void removeCardFromHand(const int cardIndex);
     void playCardToBoard(int cardIndex, Board& board);
     bool isHandEmpty() const;
     void printHand() const;
    private:
     vector<Card> hand;
     int cardsInHand;
     int playerScore;
     string name;
};

#endif // PLAYER_H
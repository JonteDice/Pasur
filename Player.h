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
     vector<Card> getHand() const;
     void drawCards(Deck& deck);
     void removeCardFromHand(const int cardIndex);
     void playCardToBoard(int cardIndex, Board& board);
     bool isHandEmpty() const;
     void printHand() const;
    private:
     vector<Card> hand;
     vector<Card> wonCards;
     int cardsInHand;
     int playerScore;
     string name;
};

#endif // PLAYER_H
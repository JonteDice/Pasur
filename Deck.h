#ifndef DECK_H
#define DECK_H

#include "Card.h" // Required to use Card
#include <iostream> // Optional, if you'll implement printDeck inline
#include <vector>

class Deck {
    public:
     Deck();
     void shuffle();
     void printDeck();
     void addCardToDeck(const Card& card);
     Card dealCard();

    private:
     std::vector<Card> deck;   
     int deckIndex;  
};


#endif // DECK_H
#ifndef BOARD_H
#define BOARD_H

#include "Card.h"
#include "Deck.h"
#include <vector>

class Board {
    
    public:
     // Constructor
     Board();

     // Deals the first 4 cards on the board
     void dealInitialCards(Deck& deck);

     // adds card on the board from the deck
     void addCard(const Card& card);

     // removes card on the board
     void removeCard(const Card& card);

     // shows the current state of the board
     void printBoard() const; 
     
     // Getter
     const std::vector<Card>& getCardsOnBoard() const;
    
    private:
     std::vector<Card> cardsOnBoard;
};

#endif // BOARD_H
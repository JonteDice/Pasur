#include "Board.h"
#include <iostream>
#include <algorithm> // For std::find

using namespace std;

// Constructor
Board::Board() {}

// Deal 4 initial cards to the board
void Board::dealInitialCards(Deck& deck) {
    for (int i = 0; i < 4; ++i) {
        try {
            Card dealtCard = deck.dealCard();
            while(dealtCard.getRank() == Card::jack) {
                deck.addCardToDeck(dealtCard);
                deck.shuffle();
                dealtCard = deck.dealCard();
            }
            cardsOnBoard.push_back(dealtCard);
        } catch (const std::out_of_range& e) {
            cout << "Not enough cards in the deck to deal initial board cards." << endl;
            break;
        }
    }
}

// Add a card to the board from the deck
void Board::addCard(const Card& card) {
    cardsOnBoard.push_back(card);
}

// Remove a specific card from the board
void Board::removeCard(const Card& card) {
    auto it = std::find(cardsOnBoard.begin(), cardsOnBoard.end(), card);
    if (it != cardsOnBoard.end()) {
        cardsOnBoard.erase(it);
    } else {
        cout << "Card not found on the board." << endl;
    }
}

// Print all cards on the board
void Board::printBoard() const {
    cout << "Cards on the board: ";
    for (const auto& card : cardsOnBoard) {
        cout << card.cardToString() << " ";
    }
    cout << endl;
}

// New function to return cards on the board
const std::vector<Card>& Board::getCardsOnBoard() const {
    return cardsOnBoard;
}

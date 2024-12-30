#include "Deck.h"
#include <algorithm> // For std::shuffle
#include <random>    // For std::random_device and std::mt19937
#include <chrono>

using namespace std;
Deck::Deck() : deckIndex(0) {
    int index = 0;
    for(int suit = Card::spades; suit <= Card::diamonds; suit++) {
        for(int rank = Card::two; rank <= Card::ace; rank++) {
            deck.push_back(Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)));
            index++;
        }
    }
}

void Deck::addCardToDeck(const Card& card) {
    deck.push_back(card);
}

Card Deck::dealCard() {
    if(!deck.empty()) {
        Card dealtCard = deck.back();
        deck.pop_back();
        return dealtCard;
    }
    throw out_of_range("No more cards in the deck");
}

void Deck::shuffle() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck.begin(), deck.end(), default_random_engine(seed));
}

void Deck::printDeck() {
    for(const auto& card : deck) {
        cout << card.cardToString() << " ";
    }
    cout << endl;
}
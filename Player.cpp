#include "Player.h"

using namespace std;

Player::Player(const string& playername) : name(playername) {}

string Player::getName() const {
    return name;
}


void Player::drawCards(Deck& deck) {
    while (hand.size() < 4) { // Ensure the hand has at most 4 cards
        hand.push_back(deck.dealCard());
    }
}

bool Player::isHandEmpty() const {
    return cardsInHand == 0;
}

void Player::printHand() const {
    cout << "Player's hand: ";
    for(const auto& card : hand) {
        cout << card.cardToString() << " ";
    }
    cout << endl;
}

void Player::removeCardFromHand(int cardIndex) {
    hand.erase(next(hand.begin(), cardIndex));
}


// Play a card from the player's hand to the board
void Player::playCardToBoard(int cardIndex, Board& board) {
    if (cardIndex < 0 || cardIndex >= hand.size()) {
        cout << "Invalid card index." << endl;
        return;
    }

    // Add the selected card to the board
    board.addCard(hand[cardIndex]);

    // Remove the card from the hand
    hand.erase(hand.begin() + cardIndex);
}
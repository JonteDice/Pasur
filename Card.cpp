#include "Card.h"

// Default constructor
Card::Card() : myRank(ace), mySuit(spades) {}

// Parameterized constructor
Card::Card(Rank rank, Suit suit) : myRank(rank), mySuit(suit) {}

void Card::setRank(Rank r) {
    myRank = r;
}

void Card::setSuit(Suit s) {
    mySuit = s;
}

// Getter for rank
Card::Rank Card::getRank() const {
    return myRank;
}

// Getter for suit
Card::Suit Card::getSuit() const {
    return mySuit;
}

// Convert Suit to string
std::string Card::suitToString() const {
    switch (mySuit) {
        case spades:   return "S";
        case hearts:   return "H";
        case clubs:    return "C";
        case diamonds: return "D";
    }
    return "Joker"; // Default, should not reach here
}

int Card::rankToInt() const {
    switch (myRank) {
        case two:   return 2;
        case three: return 3;
        case four:  return 4;
        case five:  return 5;
        case six:   return 6;
        case seven: return 7;
        case eight: return 8;
        case nine:  return 9;
        case ten:   return 10;
        case jack:  return 11;
        case queen: return 12;
        case king:  return 13;
        case ace:   return 1;
    }
    return 0; // Default, should not reach here
}

// Convert Rank to string
std::string Card::rankToString() const {
    switch (myRank) {
        case two:   return "2";
        case three: return "3";
        case four:  return "4";
        case five:  return "5";
        case six:   return "6";
        case seven: return "7";
        case eight: return "8";
        case nine:  return "9";
        case ten:   return "10";
        case jack:  return "J";
        case queen: return "Q";
        case king:  return "K";
        case ace:   return "A";
    }
    return "Joker"; // Default, should not reach here
}

std::string Card::cardToString() const {
    return rankToString()+suitToString();
}

bool Card::operator==(const Card& other) const {
    return myRank == other.myRank && mySuit == other.mySuit;
}

#include <string>
#include <iostream>

#ifndef CARD_H
#define CARD_H

using namespace std;
class Card
{
    public:
     enum Suit {spades, hearts, clubs, diamonds};
     enum Rank {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};


     Card();
     Card(Rank rank, Suit suit);

     void setRank(Rank r);
     void setSuit(Suit s);

     Rank getRank() const;
     Suit getSuit() const;
     
     int rankToInt() const;
     string suitToString() const;
     string rankToString() const;
     string cardToString() const;

     bool operator==(const Card& other) const;


    private:
     Rank myRank;
     Suit mySuit;
};

#endif // CARD_H
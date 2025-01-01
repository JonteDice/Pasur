#include <iostream>
#include "Deck.h"
#include "Player.h"
#include "Board.h"
#include "Game.h"


using namespace std;

bool testInitialCards() {
    Deck deck;
    Board board;
    bool testPassed = true;
    int range = 1000;

    for(int i = 0; i < range; i++) {
        deck = Deck();
        board = Board();
        deck.shuffle();

        board.dealInitialCards(deck);

        for (const auto& card : board.getCardsOnBoard()) {
            if (card.getRank() == Card::jack) {
                board.printBoard();
                cout << "Test failed: Jack card was dealt on the board in iteration " << i << "." << endl;
                testPassed = false;
                break;
            }
        }

        if (!testPassed) {
            break; // Exit early if the test fails
        }
    }

    return testPassed;
    }

int main() {
    // Card c(Card::ace,  Card::hearts );

    // c.setRank(Card::ten);
    // c.setSuit(Card::diamonds);


    // cout << "Card Rank: " << c.rankToString() << endl;
    // cout << "Card Suit: " << c.suitToString() << endl;
    // cout << "Card: " << c.cardToString() << endl;

    
    // Deck deck;
    // deck.shuffle();
    // deck.printDeck();

    // Player player1("player1");
    // Player player2("player2");

    // player1.drawCards(deck);
    // cout << "Player one cards are: " << endl;
    // player1.printHand();
    // cout << endl;

    // player2.drawCards(deck);
    // cout << "Player two cards are: " << endl;
    // player2.printHand();
    // cout << endl;

    // cout << "The rest of the deck is: " << endl;
    // deck.printDeck();
    // cout << endl;

    // Board board;
    // board.dealInitialCards(deck);

    // cout << "The cards on the board are: " << endl;
    // board.printBoard();
    // cout << endl;

    // player1.playCardToBoard(0, board);
    // cout << "Now the board looks like this: " << endl;
    // board.printBoard();
    // cout << endl;

    // cout << "Player hand looks like this: " << endl;
    // player1.printHand();
    // cout << endl;

    // cout << "The rest of the deck is: " << endl;
    // deck.printDeck();
    // cout << endl;

    // Test 1
    // if (testInitialCards()) {
    //     cout << "Test passed: No Jack card was dealt on the board in 1000 iterations." << endl;
    // } else {
    //     cout << "Test failed: A Jack card was dealt on the board." << endl;
    // }

    Game game;
    game.Start();

    return 0;
}
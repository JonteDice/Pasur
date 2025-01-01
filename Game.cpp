#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() : player("Player"), opponent("Opponent") {}

void Game::setup() {
    deck.shuffle();
    
    player.drawCards(deck);
    opponent.drawCards(deck);
    board.dealInitialCards(deck);

    isPlayersTurn = true;

    cout << "Game setup complete" << endl;
}

void Game::Start() {
    setup();

    player.printHand();
    opponent.printHand();
    board.printBoard();

    while(true) {
        if(isPlayersTurn) {
            cout << "Select a card to play on the board." << endl;
            int card;
            cin >> card;
            while(card < 0 || card > 3) {
                board.printBoard();
                player.printHand();
                cout << "Select a card between 0 and 3" << endl;
                cin >> card;
            }
            player.playCardToBoard(card, board);
            board.printBoard();
            player.printHand();
            break;
        }
    }

}
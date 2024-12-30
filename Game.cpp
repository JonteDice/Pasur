#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() : player("Player"), opponent("Opponent") {}

void Game::setup() {
    deck.shuffle();
    
    player.drawCards(deck);
    opponent.drawCards(deck);
    board.dealInitialCards(deck);

    cout << "Game setup complete" << endl;
}

void Game::Start() {
    setup();

    player.printHand();
    opponent.printHand();
    board.printBoard();
}
#include "Game.h"
#include <iostream>
#include <limits>  // for std::numeric_limits

// Don't pollute the global namespace; use std::cout etc. directly or define local using statements.
Game::Game()
	: player("Player"), opponent("Opponent")
{
}

void Game::setup()
{
	deck.shuffle();

	player.drawCards(deck);
	opponent.drawCards(deck);

	board.dealInitialCards(deck);

	isPlayersTurn = true;

	std::cout << "Game setup complete.\n";
}

void Game::start()
{
	setup();

	player.printHand();
	opponent.printHand();
	board.printBoard();

	// Main loop: we keep going until the game ends
	bool gameRunning = true;
	while (gameRunning) {
		if (isPlayersTurn) {
			handlePlayerTurn();
			// Switch turn to opponent if the game is continuing
			isPlayersTurn = false;
		}
		else {
			handleOpponentTurn();
			isPlayersTurn = true;
		}

		// Example: Exit condition if deck is empty or some game end condition
		if (deck.isEmpty()) {
			std::cout << "The deck is out of cards! Game Over.\n";
			gameRunning = false;
		}

		// If you want a simpler approach, break after the first player turn:
		// break;
	}
}

void Game::handlePlayerTurn()
{
	std::cout << "\n--- Player's Turn ---\n";
	board.printBoard();
	player.printHand();

	std::cout << "Select a card index to play on the board (0 to 3), or enter -1 to quit.\n";

	int cardIndex;
	while (true) {
		// Read input
		std::cin >> cardIndex;

		// Validate stream
		if (std::cin.fail()) {
			std::cin.clear(); // clear error state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
			std::cout << "Invalid input. Please enter a number between 0 and 3, or -1 to quit.\n";
			continue;
		}

		// Check for quit command
		if (cardIndex == -1) {
			std::cout << "You chose to quit the game.\n";
			std::exit(0);  // or set a gameRunning = false in start()
		}

		// Range check
		if (cardIndex < 0 || cardIndex > 3) {
			std::cout << "Card index must be between 0 and 3.\n";
			continue;
		}

		// If valid, break out and play the card
		break;
	}

	// Actually play the card
	player.playCardToBoard(cardIndex, board);

	// Show updated board state
	board.printBoard();
	player.printHand();
}

void Game::handleOpponentTurn()
{
	// Example: Opponent automatically picks a card index, or uses AI logic
	std::cout << "\n--- Opponent's Turn ---\n";

	// If you have an AI strategy, do it here:
	int opponentCardIndex = pickOpponentCardIndex();
	opponent.playCardToBoard(opponentCardIndex, board);

	std::cout << "Opponent played card index: " << opponentCardIndex << "\n";
	board.printBoard();
	opponent.printHand();
}

int Game::pickOpponentCardIndex()
{
	// For now, pick random or always pick first card:
	// e.g. always 0
	return 0;
}

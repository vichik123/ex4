#include "Mtmchkin.h"
#include "Exception.h"

int main() {
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try {
        Mtmchkin game("deck.txt");
        while (!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS) {
            game.playRound();
        }
    } catch (const DeckFileFormatError& e) {
        std::cout << e.what();
    } catch (const DeckFileInvalidSize& e) {
        std::cout << e.what();
    } catch (const DeckFileNotFound& e) {
        std::cout << e.what();
    }
}
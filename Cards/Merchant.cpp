#include "Merchant.h"
#include "../utilities.h"

Merchant::Merchant() : Card("Merchant") {}

void Merchant::applyEffect(Player &player)  {
    printMerchantInitialMessageForInteractiveEncounter(
            std::cout, player.getName(), player.getCoins());

    int choice;
    std::cin >> choice;
    while (choice != 0 && player.getCoins() < choice * 2) {
        printMerchantInsufficientCoins(std::cout);
        std::cin >> choice;
    }
    printMerchantSummary(std::cout, player.getName(), choice, choice * 2);
}
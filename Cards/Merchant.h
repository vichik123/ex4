#include <string>

//
// Created by eitan on 1/29/2024.
//

#ifndef MERCHANT_CARD_H
#define MERCHANT_CARD_H

#include "utilities.h"
#include "BattleCard.h"

class Merchant : public BattleCard {

public:
    Merchant();

    void applyEffect(Player& player) override {
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
};

Merchant::Merchant() : BattleCard("Merchant") {}

#endif //MERCHANT_CARD_H

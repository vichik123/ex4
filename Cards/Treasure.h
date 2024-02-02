#include <string>

//
// Created by eitan on 1/29/2024.
//

#ifndef TREASURE_H
#define TREASURE_H

#include "BattleCard.h"

class Treasure : public BattleCard {

public:
    Treasure();

    void applyEffect(Player& player) override {
        printTreasureMessage();
        player.updateCoins(10);
    }
};

Treasure::Treasure() : BattleCard("Treasure") {}

#endif //TREASURE_H

#include <string>

//
// Created by eitan on 1/29/2024.
//

#ifndef MANA_H
#define MANA_H

#include "BattleCard.h"

class Mana : public BattleCard {

public:
    Mana();

    void applyEffect(Player& player) override {
        bool isHealer = player.getClass() == "Healer";
        printManaMessage(isHealer);
        if (isHealer) {
            player.updateHealthPoints(10);
        }
    }
};

Mana::Mana() : BattleCard("Mana") {}

#endif //MANA_H

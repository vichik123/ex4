#include <string>

//
// Created by eitan on 1/29/2024.
//

#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "BattleCard.h"

class Barfight : public BattleCard {

public:
    Barfight();

    void applyEffect(Player& player) override {
        bool isWarrior = player.getClass() == "Warrior";
        printBarfightMessage(isWarrior);
        if (!isWarrior) {
            player.updateHealthPoints(-8);
        }
    }
};

Barfight::Barfight() : BattleCard("Barfight") {}

#endif //BARFIGHT_H

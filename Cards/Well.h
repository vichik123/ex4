#include <string>

//
// Created by eitan on 1/29/2024.
//

#ifndef WELL_H
#define WELL_H

#include "BattleCard.h"

class Well : public BattleCard {

public:
    Well();

    void applyEffect(Player& player) override {
        bool isNinja = player.getClass() == "Ninja";
        printWellMessage(isNinja);
        if (!isNinja) {
            player.updateHealthPoints(-10);
        }
    }
};

Well::Well() : BattleCard("Well") {}

#endif //WELL_H

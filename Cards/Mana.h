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
};

Mana::Mana() : BattleCard("Mana") {}

#endif //MANA_H

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
};

Barfight::Barfight() : BattleCard("Barfight") {}

#endif //BARFIGHT_H

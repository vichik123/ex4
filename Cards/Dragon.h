//
// Created by eitan on 1/13/2024.
//

#ifndef DRAGON_H
#define DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard {

public:
    Dragon();
};

Dragon::Dragon() : BattleCard(25, 1000, 100) {}

#endif //DRAGON_H

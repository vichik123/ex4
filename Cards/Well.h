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
};

Well::Well() : BattleCard("Well") {}

#endif //WELL_H

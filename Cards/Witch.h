//
// Created by eitan on 1/13/2024.
//

#ifndef WITCH_H
#define WITCH_H


#include "EnemyCard.h"

class Witch : public EnemyCard {

public:
    Witch();
};

Witch::Witch() : EnemyCard("Witch", 11, 2, 10) {}

#endif //WITCH_H

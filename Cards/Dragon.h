//
// Created by eitan on 1/13/2024.
//

#ifndef DRAGON_H
#define DRAGON_H

#include "EnemyCard.h"

class Dragon : public EnemyCard {

public:
    Dragon();
};

Dragon::Dragon() : EnemyCard("Dragon", 25, 1000, 100) {}

#endif //DRAGON_H

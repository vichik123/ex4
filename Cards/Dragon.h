//
// Created by eitan on 1/13/2024.
//

#ifndef DRAGON_H
#define DRAGON_H

#include "Card.h"

class Dragon : Card {

public:
    Dragon();
};

Dragon::Dragon() : Card(25, 1000, 100) {}

#endif //DRAGON_H

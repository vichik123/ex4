#include <string>

#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card {

public:
    Treasure();

    void applyEffect(Player& player) override;
};

#endif //TREASURE_H

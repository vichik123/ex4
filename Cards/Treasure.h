#include <string>

#ifndef TREASURE_H
#define TREASURE_H

#include "BattleCard.h"

class Treasure : public BattleCard {

public:
    Treasure();

    void applyEffect(Player& player) override;
};

#endif //TREASURE_H

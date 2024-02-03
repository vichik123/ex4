#include <string>

#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "BattleCard.h"
#include "../Players/Player.h"

class Barfight : public BattleCard {

public:
    Barfight();

    void applyEffect(Player& player) override;
};

#endif //BARFIGHT_H

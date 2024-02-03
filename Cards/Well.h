#include <string>

#ifndef WELL_H
#define WELL_H

#include "BattleCard.h"

class Well : public BattleCard {

public:
    Well();

    void applyEffect(Player& player) override;
};

#endif //WELL_H

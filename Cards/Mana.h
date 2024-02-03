#include <string>

#ifndef MANA_H
#define MANA_H

#include "BattleCard.h"

class Mana : public BattleCard {

public:
    Mana();

    ~Mana() override = default;

    void applyEffect(Player& player) override;
};

#endif //MANA_H

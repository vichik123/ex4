//
// Created by eitan on 1/13/2024.
//

#ifndef ENEMY_CARD_H
#define ENEMY_CARD_H

#include "Card.h"

class BattleCard : public Card {

protected:
    int force;
    int loot;
    int loss;

public:
    BattleCard(std::string name, int force, int loot, int loss);

    ~BattleCard() override = default;

    void applyEffect(Player& player) override;

    int getForce() const;

    int getLoot() const;

    int getLoss() const;

    friend std::ostream& operator<<(std::ostream& os, const BattleCard& card);
};

#endif //ENEMY_CARD_H

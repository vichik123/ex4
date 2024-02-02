//
// Created by eitan on 1/13/2024.
//

#ifndef ENEMY_CARD_H
#define ENEMY_CARD_H

#include <utility>

#include "BattleCard.h"

class EnemyCard : public BattleCard {

protected:
    int force;
    int loot;
    int loss;

public:
    EnemyCard(std::string name, int force, int loot, int loss);

    int getForce() const;
    int getLoot() const;
    int getLoss() const;
};

EnemyCard::EnemyCard(std::string name, int force, int loot, int loss) :
        BattleCard(std::move(name)), force(force), loot(loot), loss(loss) {}


#endif //ENEMY_CARD_H

//
// Created by eitan on 1/13/2024.
//

#ifndef ENEMY_CARD_H
#define ENEMY_CARD_H

#include <utility>

#include "BattleCard.h"
#include "../utilities.h"

class EnemyCard : public BattleCard {

protected:
    int force;
    int loot;
    int loss;

public:
    EnemyCard(std::string name, int force, int loot, int loss);

    void applyEffect(Player& player) override {
        printCardDetails(std::cout, this->name);
        printMonsterDetails(std::cout, force, loss, loot, loot == 1000);
        printEndOfCardDetails(std::cout);
        if (player.getAttackPower() >= force) {
            player.updateCoins(loot);
        } else {
            player.updateHealthPoints(-loss);
        }
    }

    int getForce() const;
    int getLoot() const;
    int getLoss() const;
};

EnemyCard::EnemyCard(std::string name, int force, int loot, int loss) :
        BattleCard(std::move(name)), force(force), loot(loot), loss(loss) {}


#endif //ENEMY_CARD_H

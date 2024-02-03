//
// Created by eitan on 1/13/2024.
//

#ifndef ENEMY_CARD_H
#define ENEMY_CARD_H

#include <utility>

#include "Card.h"

class EnemyCard : public Card {

protected:
    int force;
    int loot;
    int loss;

public:
    EnemyCard(std::string name, int force, int loot, int loss);

    ~EnemyCard() override = default;

    void applyEffect(Player& player) override;

    int getForce() const;

    int getLoot() const;

    int getLoss() const;

    friend std::ostream& operator<<(std::ostream& os, const EnemyCard& card);
};

#endif //ENEMY_CARD_H

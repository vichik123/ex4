#include <utility>
#include <string>

//
// Created by eitan on 1/29/2024.
//

#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H

#include "../Players/Player.h"

class BattleCard {

protected:
    std::string name;

public:
    explicit BattleCard(std::string name);

	std::string getName() const;

    virtual void applyEffect(Player& player);

    friend std::ostream& operator<<(std::ostream& os, BattleCard& card) {
        return os << card.name;
    }
};

BattleCard::BattleCard(std::string name) : name(std::move(name)) {}

#endif //BATTLE_CARD_H

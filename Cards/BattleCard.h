#include <utility>

//
// Created by eitan on 1/29/2024.
//

#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H

class BattleCard {

protected:
    std::string name;

public:
    explicit BattleCard(std::string name);

    friend std::ostream& operator<<(std::ostream& os, BattleCard& card) {
        return os << card.name;
    }
};

BattleCard::BattleCard(std::string name) : name(std::move(name)) {}

#endif //BATTLE_CARD_H

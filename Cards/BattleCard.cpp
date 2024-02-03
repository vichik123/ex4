#include "BattleCard.h"
#include "../Players/Player.h"
#include <string>

BattleCard::BattleCard(std::string name) : name(std::move(name)) {}

BattleCard::~BattleCard() = default;

std::string BattleCard::getName() const {
    return name;
}

std::ostream &operator<<(std::ostream &os, const BattleCard &card) {
    os << card.name;
    return os;
}

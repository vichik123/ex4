#include "BattleCard.h"
#include "../Players/Player.h"
#include <string>

BattleCard::BattleCard(std::string name) : name(std::move(name)) {}

std::string BattleCard::getName() const {
    return name;
}

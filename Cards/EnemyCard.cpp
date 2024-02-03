#include "EnemyCard.h"
#include "../utilities.h"

EnemyCard::EnemyCard(std::string name, int force, int loot, int loss) :
        BattleCard(std::move(name)), force(force), loot(loot), loss(loss) {}

void EnemyCard::applyEffect(Player &player) {
    printCardDetails(std::cout, this->name);
    printMonsterDetails(std::cout, force, loss, loot, loot == 1000);
    printEndOfCardDetails(std::cout);
    if (player.getAttackPower() >= force) {
        player.updateCoins(loot);
    } else {
        player.updateHealthPoints(-loss);
    }
}

int EnemyCard::getForce() const {
    return force;
}

int EnemyCard::getLoot() const {
    return loot;
}

int EnemyCard::getLoss() const {
    return loss;
}
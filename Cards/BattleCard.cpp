#include "BattleCard.h"
#include "../utilities.h"

BattleCard::BattleCard(std::string name, int force, int loot, int loss) :
        Card(std::move(name)), force(force), loot(loot), loss(loss) {}

void BattleCard::applyEffect(Player &player) {
    if (player.getAttackPower() >= force) {
        player.updateCoins(loot);
        player.winBattle();
        printWinBattle(player.getName(), this->getName());
    } else {
        player.updateHealthPoints(-loss);
        player.loseBattle(player.getHP() < 1);
        printLossBattle(player.getName(), this->getName());
    }
}

int BattleCard::getForce() const {
    return force;
}

int BattleCard::getLoot() const {
    return loot;
}

int BattleCard::getLoss() const {
    return loss;
}

std::ostream &operator<<(std::ostream &os, const BattleCard &card) {
    printCardDetails(os, card.name);
    printMonsterDetails(os, card.force, card.loss, card.loot, card.name == "Dragon");
    return os;
}
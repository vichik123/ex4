#include "EnemyCard.h"
#include "../utilities.h"

EnemyCard::EnemyCard(std::string name, int force, int loot, int loss) :
        Card(std::move(name)), force(force), loot(loot), loss(loss) {}

void EnemyCard::applyEffect(Player &player) {
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

int EnemyCard::getForce() const {
    return force;
}

int EnemyCard::getLoot() const {
    return loot;
}

int EnemyCard::getLoss() const {
    return loss;
}

std::ostream &operator<<(std::ostream &os, const EnemyCard &card) {
    printCardDetails(os, card.name);
    printMonsterDetails(os, card.force, card.loss, card.loot, card.name == "Dragon");
    return os;
}
#include "Treasure.h"
#include "../utilities.h"

Treasure::Treasure() : Card("Treasure") {}

void Treasure::applyEffect(Player &player) {
    printTreasureMessage();
    player.updateCoins(10);
}
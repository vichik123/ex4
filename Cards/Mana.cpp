#include "Mana.h"
#include "../utilities.h"

Mana::Mana() : Card("Mana") {}

void Mana::applyEffect(Player &player) {
    bool isHealer = player.getClass() == "Healer";
    printManaMessage(isHealer);
    if (isHealer) {
        player.updateHealthPoints(10);
    }
}
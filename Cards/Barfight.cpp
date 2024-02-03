#include "Barfight.h"
#include "../utilities.h"

Barfight::Barfight() : Card("Barfight") {}

void Barfight::applyEffect(Player &player) {
    bool isWarrior = player.getClass() == "Warrior";
    printBarfightMessage(isWarrior);
    if (!isWarrior) {
        player.updateHealthPoints(-10);
    }
}
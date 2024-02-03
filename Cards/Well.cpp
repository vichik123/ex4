#include "Well.h"
#include "../utilities.h"

Well::Well() : BattleCard("Well") {}

void Well::applyEffect(Player &player)  {
    bool isNinja = player.getClass() == "Ninja";
    printWellMessage(isNinja);
    if (!isNinja) {
        player.updateHealthPoints(-10);
    }
}
#include <string>

#ifndef MANA_H
#define MANA_H

#include "Card.h"

class Mana : public Card {

public:
    Mana();

    void applyEffect(Player& player) override;
};

#endif //MANA_H

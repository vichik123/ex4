#include <string>

#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card {

public:
    Treasure();

    ~Treasure() override = default;

    void applyEffect(Player& player) override;
};

#endif //TREASURE_H

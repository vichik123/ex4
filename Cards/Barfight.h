#include <string>

#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"
#include "../Players/Player.h"

class Barfight : public Card {

public:
    Barfight();

    ~Barfight() override = default;

    void applyEffect(Player& player) override;
};

#endif //BARFIGHT_H

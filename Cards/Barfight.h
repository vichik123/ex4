#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

class Barfight : public Card {

public:
    Barfight();

    void applyEffect(Player& player) override;
};

#endif //BARFIGHT_H

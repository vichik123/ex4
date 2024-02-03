#include <string>

#ifndef WELL_H
#define WELL_H

#include "Card.h"

class Well : public Card {

public:
    Well();

    ~Well() override = default;

    void applyEffect(Player& player) override;
};

#endif //WELL_H

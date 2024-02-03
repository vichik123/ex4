#include <string>

#ifndef MERCHANT_CARD_H
#define MERCHANT_CARD_H

#include "BattleCard.h"

class Merchant : public BattleCard {

public:
    Merchant();

    ~Merchant() override = default;

    void applyEffect(Player& player) override;
};

#endif //MERCHANT_CARD_H

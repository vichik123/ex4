#include <string>

//
// Created by eitan on 1/29/2024.
//

#ifndef MERCHANT_CARD_H
#define MERCHANT_CARD_H

#include "BattleCard.h"

class Merchant : public BattleCard {

public:
    Merchant();
};

Merchant::Merchant() : BattleCard("Merchant") {}

#endif //MERCHANT_CARD_H

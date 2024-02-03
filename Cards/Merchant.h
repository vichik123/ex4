#ifndef MERCHANT_CARD_H
#define MERCHANT_CARD_H
#include "Card.h"

class Merchant : public Card {

public:
    Merchant();

    void applyEffect(Player& player) override;
};

#endif //MERCHANT_CARD_H

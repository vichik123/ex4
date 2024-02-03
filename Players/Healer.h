#include <utility>

#ifndef HEALER_H
#define HEALER_H

#include "Player.h"

class Healer : public Player {

public:
    explicit Healer(std::string name);

    void updateHealthPoints(int amount) override {
        if (amount > 0) {
            Player::updateHealthPoints(2 * amount);
        } else {
            Player::updateHealthPoints(amount);
        }
    }

};

#endif //HEALER_H

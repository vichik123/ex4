#include <utility>

#ifndef HEALER_H
#define HEALER_H

#include "Player.h"

class Healer : public Player {

public:
    explicit Healer(std::string name);

    void updateHealthPoints(int amount) override {
        if (amount > 0) {
            healthPoints += amount * 2;
        } else {
            healthPoints += amount;
        }
    }

};

#endif //HEALER_H

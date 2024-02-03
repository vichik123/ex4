#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H
#include "../Players/Player.h"
#include <string>

class Card {

protected:
    std::string name;

public:
    explicit Card(std::string name);

    virtual ~Card();

	std::string getName() const;

    virtual void applyEffect(Player& player) = 0;

    friend std::ostream &operator<<(std::ostream &os, const Card &card);
};

#endif //BATTLE_CARD_H

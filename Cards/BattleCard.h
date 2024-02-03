#include <string>
#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H
#include "../Players/Player.h"

class BattleCard {

protected:
    std::string name;

public:
    explicit BattleCard(std::string name);

    virtual ~BattleCard();

	std::string getName() const;

    virtual void applyEffect(Player& player) = 0;

    friend std::ostream& operator<<(std::ostream& os, BattleCard& card) {
        return os << card.name;
    }
};

#endif //BATTLE_CARD_H

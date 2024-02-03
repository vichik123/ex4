#include "Card.h"
#include "../Players/Player.h"
#include <string>

Card::Card(std::string name) : name(std::move(name)) {}

Card::~Card() = default;

std::string Card::getName() const {
    return name;
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << card.name;
    return os;
}

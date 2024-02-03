//
// Created by eitan on 1/29/2024.
//
#include "Player.h"
#include "../Cards/EnemyCard.h"
#include "../utilities.h"

#include <utility>

int Player::nextId = 1;

Player::Player(std::string name, std::string className) :
    name(std::move(name)), className(std::move(className)), level(1), force(5), healthPoints(MAX_HP), coins(10), uniqueId(nextId++) {}

void Player::updateCoins(int amount) {
    coins += amount;
}

void Player::updateHealthPoints(int amount) {
    healthPoints += amount;
    if (healthPoints < 0) {
        healthPoints = 0;
    } else if (healthPoints > 100) {
        healthPoints = 100;
    }
}

int Player::getAttackPower() {
    return force + level;
}

std::string Player::getClass() {
    return className;
}

const std::string &Player::getName() const {
    return name;
}

int Player::getCoins() const {
    return coins;
}

int Player::getLevel() const {
    return level;
}

int Player::getHP() const {
    return healthPoints;
}

int Player::getUniqueId() const {
	return uniqueId;
}

void Player::winBattle() {
    if (level < 10) {
        this->level++;
    }
}

void Player::loseBattle(bool died) {
    if (force > 0 && !died) {
        this->force--;
    }
}

bool operator==(const Player& one, const Player& other) {
	return one.getUniqueId() == other.getUniqueId();
}

std::ostream& operator<<(std::ostream& os, Player const& player) {
    printPlayerDetails(os, player.name, player.className, player.level, player.force, player.healthPoints, player.coins);
    return os;
}

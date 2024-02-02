//
// Created by eitan on 1/29/2024.
//
#include "Player.h"
#include "../Cards/EnemyCard.h"

#include <utility>

Player::Player(std::string name, std::string className) :
    name(std::move(name)), className(std::move(className)), level(1), force(5), healthPoints(MAX_HP), coins(10) {}

void Player::updateCoins(int amount) {
    coins += amount;
}

void Player::updateHealthPoints(int amount) {
    healthPoints += amount;
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

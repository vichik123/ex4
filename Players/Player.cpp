//
// Created by eitan on 1/29/2024.
//
#include "Player.h"

#include <utility>

Player::Player(std::string  name) :
    name(std::move(name)), level(1), force(5), healthPoints(MAX_HP), coins(10) {}

void Player::updateCoins(int amount) {
    coins += amount;
}

void Player::updateHealthPoints(int amount) {
    healthPoints += amount;
}

int Player::getAttackPower() {
    return force + level;
}
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H
#define MAX_HP 100

class BattleCard;

class Player {

protected:
    std::string name;
    std::string className;
    int level;
    int force;
    int healthPoints;
    int coins;
	static int nextId;
	int uniqueId;

public:
    explicit Player(std::string name, std::string className);

    virtual ~Player();

    /**
     * Update the number of coins the player has.
     *
     * @param amount is how much to change.
     *          This can be positive or negative.
     */
    virtual void updateCoins(int amount);

    /**
     * Update the health points of the player.
     *
     * @param amount is how many health points are given
     *              or lost (positive or negative respectively).
     */
    virtual void updateHealthPoints(int amount);

    /**
     * Gets the total attack power, defined as force + level.
     *
     * @return the total attack power.
     */
    virtual int getAttackPower();

    std::string getClass();

    const std::string &getName() const;

    int getCoins() const;

    int getLevel() const;

    int getHP() const;

	int getUniqueId() const;

    void winBattle();

    void loseBattle(bool died);

	friend bool operator==(const Player& one, const Player& other);

    friend std::ostream& operator<<(std::ostream& os, Player const& player);
};

#endif //PLAYER_H

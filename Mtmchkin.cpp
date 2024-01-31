// Mtmchkin.cpp

#include "Mtmchkin.h"
#include "utilities.h"
#include <iostream>
#include <vector>
#include <fstream>
#define MAX_PLAYERS 6
#define MIN_PLAYERS 2



void buildDeck(const std::string &fileName) {

	std::ifstream file(filename);
	
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return deck;
    }

    std::string cardName;

	while (std::getline(file, cardName)) {
		if (cardName == "Barfight") {
			BattleCard* card = new Barfight();
		} else if (cardName == "Gremlin") {
			BattleCard* card = new Gremlin();
		} else if (cardName == "Dragon") {
			BattleCard* card = new Dragon();
		} else if (cardName == "Gremlin") {
			BattleCard* card = new Gremlin();
		} else if (cardName == "Mana") {
			BattleCard* card = new Mana();
		} else if (cardName == "Merchant") {
			BattleCard* card = new Merchant();
		} else if (cardName == "Treasure") {
			BattleCard* card = new Treasure();
		} else if (cardName == "Well") {
			BattleCard* card = new Well();
		} else if (cardName == "Witch") {
			BattleCard* card = new Witch();
		} else if (cardName == "EnemyCard") {
			BattleCard* card = new EnemyCard();
		}
        this->m_deck.push_back(card);
    }
}

Player* buildPlayer(const std::string &name, const std::string &className) {
	if (className == "Ninja") {
		Player* player = new Ninja(name);
	} else if (className == "Healer") {
		Player* player = new Healer(name);
	} else if (className == "Warrior") {
		Player* player = new Warrior(name);
	}
	return player;
}

void getNumberOfPlayers() {
	printEnterTeamSizeMessage();
    std::cin >> this->m_playerCount;
    while (this->m_playerCount < MIN_PLAYERS || this->m_playerCount > MAX_PLAYERS) {
		printInvalidTeamSize();
        //lines to clean buffer
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		printEnterTeamSizeMessage();
        std::cin >> this->m_playerCount;
    }
}

bool validClass(const std::string& className) {
    return (className == "Healer" || className == "Ninja" || className == "Warrior");
}

bool validName(const std::string& name) {
    if (name.length() > 16) {
        return false;
    }
    
    for (char ch : name) {
        if (!(('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z'))) {
            return false;
        }
    }

	return true;
}

void getPlayer() {
	std::string currentName;
	std::string currentClass;
	printInsertPlayerMessage();
	std::cin >> currentName >> currentClass;
	//no measures were taken to prevent input under/above 2 words yet
	while (!validName(currentName) || !validClass(currentClass)) {
		if (!validName(currentName)){
			printInvalidName();
		}
		if (!validClass(currentClass)){
			printInvalidClass();
		}
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		printInsertPlayerMessage();
		std::cin >> currentName >> currentClass;
	}
	this->m_players.push_back(buildPlayer(currentName, currentClass));
}

Mtmchkin::Mtmchkin(const std::string &fileName) {
	buildDeck(fileName);
    printStartGameMessage();
	getNumberOfPlayers();
	for (int i = 0; i < m_playerCount; i++) {
		getPlayer();
	}
}

void Mtmchkin::playRound() {
	printRoundStartMessage();
	this->m_roundCount++;
}

void Mtmchkin::printLeaderBoard() const {
	printRoundStartMessage();
	for (int i = 0; i < this->m_playerCount; i++) {
		printPlayerLeaderBoard(int_ranking, player)
	}
}

bool isFinished(const Player &player) {
	int hp = player.getHP();
	int level = player.getLevel();
	if (hp == 0 || level == 10){
		return true;
	}
	return false;
}

bool Mtmchkin::isGameOver() const {
	for (const Player& player : this->m_players) {
		if (!isFinished(player)) {
			return false;
		}
	}
	return false;
}

int Mtmchkin::getNumberOfRounds() const {
    return this->getNumberOfRounds(); 
}


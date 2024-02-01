// Mtmchkin.cpp

#include "Mtmchkin.h"
#include "utilities.h"
#include "Players/Player.h"
#include "Cards/BattleCard.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#define MAX_PLAYERS 6
#define MIN_PLAYERS 2
#define MAX_LEVEL 10
#define ZERO 0
#define MAX_NAME_LENGTH 15


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
    if (name.length() > MAX_NAME_LENGTH) {
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

void playCard(Player& player) {
	// card = this->m_deck[0] ~ first card in the deck
	// std::string cardType = card.printType();
	// std::string playerType = player.printType(); //not sure if needed
	// thought process: if (cardType == "Treasure") {
	//     player.getTreasure(); //differentiating between player types happens automatically
	// }
}

void Mtmchkin::playRound() {
	printRoundStartMessage();
	for (const Player& player : this->m_players) {
		printTurnStartMessage(player.getName());
		
		playCard(player);

		if (player.getLevel() == MAX_LEVEL) {
			this->m_leaderboards.insert(this->m_leaderboard.begin() + this->m_haveWon, player);
			this->m_haveWon++;
		}
		if (player.getHP() == ZERO) {
			this->m_leaderboards.insert(this->m_leaderboard.end() - this->m_haveLost, player);
			this->m_haveLost++;
		}
		if (isGameOver()) {
			printGameEndMessage();
			//what now???
			return;
		}
	}
	this->m_roundCount++;
}

void insertAtIndex(std::vector<Player>& vec, const Player& player, int index) {
    vec.insert(vec.begin() + index, player);
	return;
}

void Mtmchkin::printLeaderBoard() const {
	printRoundStartMessage();
	for (int i = 0; i < this->m_playerCount; i++) {
		printPlayerLeaderBoard(i + 1, this->m_leaderboard[i]);
	}
}

bool isFinished(const Player &player) {
	int hp = player.getHP();
	int level = player.getLevel();
	if (hp == ZERO || level == MAX_LEVEL){
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


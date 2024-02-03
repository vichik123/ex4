#include "Mtmchkin.h"
#include "utilities.h"
#include "Exception.h"
#include "Players/Player.h"
#include "Cards/BattleCard.h"
#include "Cards/Treasure.h"
#include "Cards/Gremlin.h"
#include "Cards/Dragon.h"
#include "Cards/Barfight.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Witch.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include <iostream>
#include <vector>
#include <fstream>

#define MAX_PLAYERS 6
#define MIN_PLAYERS 2
#define MAX_LEVEL 10
#define ZERO 0
#define MAX_NAME_LENGTH 15

void buildDeck(std::vector<BattleCard*>& deck, const std::string& fileName) {
	std::ifstream file(fileName);
	
    if (!file.is_open()) {
		throw DeckFileNotFound();
    }

    std::string cardName;
	int lineNumber = 0;
	while (std::getline(file, cardName)) {
		lineNumber++;
        BattleCard* card;
		if (cardName == "Barfight") {
			card = new Barfight();
		} else if (cardName == "Gremlin") {
			card = new Gremlin();
		} else if (cardName == "Dragon") {
			card = new Dragon();
		} else if (cardName == "Mana") {
			card = new Mana();
		} else if (cardName == "Merchant") {
			card = new Merchant();
		} else if (cardName == "Treasure") {
			card = new Treasure();
		} else if (cardName == "Well") {
			card = new Well();
		} else if (cardName == "Witch") {
			card = new Witch();
		} else {
			throw DeckFileFormatError(lineNumber);
		}

        deck.insert(deck.begin(), card);
    }

	if (lineNumber < 5) {
		throw DeckFileInvalidSize();
	}

}

Player* buildPlayer(const std::string &name, const std::string &className) {
    Player *player = nullptr;
	if (className == "Ninja") {
		player = new Ninja(name);
	} else if (className == "Healer") {
		player = new Healer(name);
	} else if (className == "Warrior") {
		player = new Warrior(name);
    }
	return player;
}

int getNumberOfPlayers() {
    int playerCount;
	printEnterTeamSizeMessage();
    std::cin >> playerCount;
    while (playerCount < MIN_PLAYERS || playerCount > MAX_PLAYERS) {
		printInvalidTeamSize();
        //lines to clean buffer
		//std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		printEnterTeamSizeMessage();
        std::cin >> playerCount;
    }
    return playerCount;
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

void getPlayer(std::vector<Player*>& players) {
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
//		std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		printInsertPlayerMessage();
		std::cin >> currentName >> currentClass;
	}
	players.insert(players.begin(), buildPlayer(currentName, currentClass));
}

Mtmchkin::Mtmchkin(const std::string &fileName) {
	try {
	buildDeck(this->m_deck, fileName);
	} catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	
    printStartGameMessage();
	this->m_playerCount = getNumberOfPlayers();
	for (int i = 0; i < m_playerCount; i++) {
		getPlayer(this->m_players);
	}

    for (Player *player: this->m_players) {
        m_leaderboard.push_back(player);
    }
}

void playCard(std::vector<BattleCard*>& deck, Player& player) {
	BattleCard* card = deck.back();
    deck.pop_back();
    deck.insert(deck.begin(), card);
    card->applyEffect(player);
}

void Mtmchkin::playRound() {
	printRoundStartMessage(this->m_roundCount);
	for (Player* player : this->m_players) {
		printTurnStartMessage(player->getName());
		
		playCard(this->m_deck, *player);

		if (player->getLevel() == MAX_LEVEL) {
			this->m_leaderboard.insert(this->m_leaderboard.begin() + this->m_haveWon, player);
			this->m_haveWon++;
		}
		if (player->getHP() <= ZERO) {
			this->m_leaderboard.insert(this->m_leaderboard.end() - this->m_haveLost, player);
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

void insertAtIndex(std::vector<Player*>& vec, Player* player, int index) {
    vec.insert(vec.begin() + index, player);
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
	for (int i = 0; i < this->m_playerCount; i++) {
        const Player* player = this->m_leaderboard[i];
		printPlayerLeaderBoard(i + 1, *player);
	}
}

bool isFinished(const Player* player) {
	int hp = player->getHP();
	int level = player->getLevel();
	if (hp == ZERO || level == MAX_LEVEL){
		return true;
	}
	return false;
}

bool Mtmchkin::isGameOver() const {
	for (const Player* player : this->m_players) {
		if (!isFinished(player)) {
			return false;
		}
	}
	return true;
}

int Mtmchkin::getNumberOfRounds() const {
    return this->m_roundCount;
}


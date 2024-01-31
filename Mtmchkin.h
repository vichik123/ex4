#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <vector>

enum class GameStatus {
    Win, Loss, MidGame
};

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
private:
	int m_roundCount = 0;
	int m_playerCount;
    vector<Player> m_players;
	vecotr<Player> m_leaderboard;
    vector<Card> m_deck;
    GameStatus m_status;
	int m_haveWon = 0;
	int m_haveLost = 0;
};



#endif /* MTMCHKIN_H_ */

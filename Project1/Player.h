#pragma once
ref class Player
{
protected:
	int money;
	int numOfAces;
	int totalCardValue;

public:
	Player();
	Player(int);
	void Bet(int wager);
	void resetPlayer(int);
	int getPlayerMoney();
	void setPlayerMoney(int);
	int getNumOfAces();
	void incNumOfAces(int);
	int getTotalCardValue();
	void setTotalCardValue(int);
};


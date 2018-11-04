#pragma once
class _Player
{
protected:
	int money;
	int numOfAces;
	int totalCardValue;
	int cardPos1, cardPos2;

public:
	_Player();
	_Player(int);
	void Bet(int wager);
	void resetPlayer(int);
	int getPlayerMoney();
	void setPlayerMoney(int);
	int getNumOfAces();
	void incNumOfAces(int);
	int getTotalCardValue();
	void setTotalCardValue(int);
};


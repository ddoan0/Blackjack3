#include "_Player.h"

_Player::_Player()
{
	money = 0;
	numOfAces = 0;
	totalCardValue = 0;
}

_Player::_Player(int startingMoney)
{
	money = startingMoney;
	numOfAces = 0;
	totalCardValue = 0;
}

int _Player::getPlayerMoney()
{
	return money;
}

void _Player::setPlayerMoney(int amount)
{
	money = amount;
}

int _Player::getNumOfAces()
{
	return numOfAces;
}

// Used for ace dual values (1 or 11)
void _Player::incNumOfAces(int x)
{
	numOfAces += x;
}

// The bet method returns the amount to add to the pot total money
void _Player::Bet(int wager)
{
	// check to see if the player has enough money to bet
	if (wager <= money)
	{
		money -= wager;
	}
}

void _Player::resetPlayer(int initialValue)
{
	money = initialValue;
	numOfAces = 0;
	totalCardValue = 0;
}

int _Player::getTotalCardValue()
{
	return totalCardValue;
}

void _Player::setTotalCardValue(int cardValue)
{
	totalCardValue = cardValue;
}
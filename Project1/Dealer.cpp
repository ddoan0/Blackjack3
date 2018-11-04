#include "Dealer.h"

Dealer::Dealer()
{
	money = 0;
	numOfAces = 0;
	totalCardValue = 0;
}

void Dealer::Bet(int playerBet)
{
	// this bet does not need to check for proper input because the player side will have taken care of it
	money += playerBet;
}

void Dealer::resetPlayer()
{
	// dealer does not have an initial money value
	money = 0;
	numOfAces = 0;
	totalCardValue = 0;
}

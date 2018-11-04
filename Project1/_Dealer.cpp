#include "_Dealer.h"

_Dealer::_Dealer()
{
	money = 0;
	numOfAces = 0;
	totalCardValue = 0;
}

void _Dealer::Bet(int playerBet)
{
	// this bet does not need to check for proper input because the player side will have taken care of it
	money += playerBet;
}

void _Dealer::resetPlayer()
{
	// dealer does not have an initial money value
	money = 0;
	numOfAces = 0;
	totalCardValue = 0;
}

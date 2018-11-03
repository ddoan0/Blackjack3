#pragma once
#include "_Player.h"
#include "_Deck.h"
#include <vector>


class _Blackjackgame
{
	// fields
public:
	int totalBetAmount;
	_Player *player;
	_Player *dealer;
	_Deck *d;

	// methods
public:
	_Blackjackgame();
	void set_bet_amount(int betAmount);
	int getTotalBetAmount();
	void start_game();
	void startAnotherRound();
	std::string hit(_Player *);
	void stay();
	void checkAces(_Player *);
	std::string winnerIsDetermined(_Player *, _Player *);
};


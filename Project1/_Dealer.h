#pragma once
#include "_Player.h"
class _Dealer : public _Player
{
public:
	_Dealer();
	void Bet(int);
	void resetPlayer();
};
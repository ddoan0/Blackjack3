#include "_Blackjackgame.h"

// constructor
_Blackjackgame::_Blackjackgame()
{
	player = new _Player(1000);
	dealer = new _Player(0);
	d = new _Deck();
	totalBetAmount = 0;
}

int _Blackjackgame::getTotalBetAmount()
{
	return totalBetAmount;
}

void _Blackjackgame::set_bet_amount(int betAmount)
{
	// player has enough money to bet that amount
	if (player->getPlayerMoney() >= betAmount && betAmount > 0)
	{
		player->setPlayerMoney(player->getPlayerMoney() - betAmount);
		totalBetAmount += betAmount;
		dealer->setPlayerMoney(dealer->getPlayerMoney() + totalBetAmount);
	}
}


// this needs to initialize the game state elements
// dealer gets 2 cards, but one is face down
// player gets 2 cards face up
void _Blackjackgame::start_game()
{
	// Set values of cards and ensure that none of the cards from the deck have been used
	d->populate();
	d->resetDeck();
	player->resetPlayer(player->getPlayerMoney());
	dealer->resetPlayer(dealer->getPlayerMoney());
	totalBetAmount = 0;
}

// not needed. functionality moved to start game.
void _Blackjackgame::startAnotherRound()
{
	d->resetDeck();
	player->resetPlayer(player->getPlayerMoney());
	dealer->resetPlayer(dealer->getPlayerMoney());
}

// player/dealer gets one card. need to add check to make sure player has not bust yet or has not already held.
// return the location of the card image
std::string _Blackjackgame::hit(_Player *player)
{
	int pindex = rand() % 52;
	while (d->deck[pindex]->hasBeenUsed)
	{
		pindex = rand() % 52;
	}
	d->deck[pindex]->hasBeenUsed = true;
	// check to see if it is an ACE
	if (pindex == 0 || pindex == 13 || pindex == 26 || pindex == 39)
	{
		if (player->getTotalCardValue() + 11 > 21) { player->setTotalCardValue(player->getTotalCardValue() + 1); }
		else { player->setTotalCardValue(player->getTotalCardValue() + 11); }
		player->incNumOfAces(1);
	}
	// it is not an ace
	else { player->setTotalCardValue(player->getTotalCardValue() + d->deck[pindex]->cardValue); }
	return d->deck[pindex]->img_loc;
}

// called after 2nd draw to determine whether any aces need to use the 1 value
void _Blackjackgame::checkAces(_Player *player)
{
	while (player->getNumOfAces() > 0 && player->getTotalCardValue() > 21)
	{
		player->incNumOfAces(-1);
		player->setTotalCardValue(player->getTotalCardValue() - 10);
	}
}

// player stays and then the dealer plays
void _Blackjackgame::stay()
{

}

std::string _Blackjackgame::winnerIsDetermined(_Player *player, _Player *dealer)
{
	int playerTotal = player->getTotalCardValue();
	int dealerTotal = dealer->getTotalCardValue();
	// Compare dealer total to player total
	if ((playerTotal > dealerTotal || dealerTotal > 21) && playerTotal <= 21)
	{
		int i = player->getPlayerMoney() + 2 * dealer->getPlayerMoney();
		player->setPlayerMoney(i);
		dealer->setPlayerMoney(0);
		return "Player Win!";
	}
	else if (playerTotal == dealerTotal || (playerTotal > 21 && dealerTotal > 21))
	{
		return "Tie!";
	}
	else
	{
		return "Dealer Win!";
	}
}
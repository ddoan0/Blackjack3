#include "_Deck.h"

_Deck::_Deck()
{
	// when a deck is instantiated, all 52 cards also instantiated
	
	for (int i = 0; i < deckSize; i++)
	{
		deck[i] = new _Card();
	}
	// set suits array - 0 = spade, 1 = club, 2 = diamond, 3 = heart
	suitsTotal[0] = "s";
	suitsTotal[1] = "c";
	suitsTotal[2] = "d";
	suitsTotal[3] = "h";
}

void _Deck::resetDeck()
{
	for (int i = 0; i < deckSize; i++) {
		deck[i]->hasBeenUsed = false;
	}
}

bool _Deck::deckHasBeenReset()
{
	// cycle through the entire deck of cards to see if a card has been used yet.
	for (int i = 0; i < deckSize; i++) {
		if (deck[i]->hasBeenUsed) return false;
	}
	return true;
}

void _Deck::shuffle()
{

}

void _Deck::populate()
{
	/*
*	 Set values of the deck. Aces should have a value of 1 or 11
*	 However, each card will get a second value so that we do not have to search for Aces.
*
*	 Indices of the cards at initialization
*	 0-12 Spades		10-12 face cards
*	 13-25 Clubs		23-25 face cards
*	 26-38 Diamonds		36-38 face cards
*	 39-51 Hearts		49-51 face cards
*/
	int cardName = 1;
	int count = 0;
	int j = 1; // value of the cards
	// count to reset for face cards
	int suitCount = 0;

	for (int i = 0; i < deckSize; i++)
	{
		// aCardValue to be only used for Aces
		deck[i]->aCardValue = 11;
		deck[i]->cardValue = j++;

		deck[i]->img_loc = "images\\" + cardName.ToString + ".png";
		cardName++;

		if (j >= 10) // when j = 10, let the value persist until all face cards are accounted for
		{
			j = 10;
			count++;
			if (count > 4) // when count reaches 5, all face cards for that suit has been assigned a value of 10
			{
				j = 1;
				count = 0;
			}
		}

		// set suits. if index is multiple of 13, change suit
		deck[i]->suit = suitsTotal[suitCount];
		if (i == 12 || i == 25 || i == 38) // end of one set of suits
		{
			suitCount++;
			j = 1;
		}
	}
}

// pass in pindex and pindex2 of the cards to determine whether the first two cards are Aces.
bool _Deck::cardHasBeenDrawn(int index)
{
	if (deck[index]->hasBeenUsed) return true;
	return false;
}
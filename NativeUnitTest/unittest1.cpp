#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project1/_Card.cpp"
#include "../Project1/_Deck.cpp"
#include "../Project1/_Player.cpp"
#include "../Project1/_Blackjackgame.cpp"
#include "../Project1/_Dealer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest
{		
	TEST_CLASS(PlayerTest)
	{
	public:
		// Test to make sure money gets put into the player correctly
		TEST_METHOD(PlayerInstantiationTest)
		{
			_Player p1(250);
			Assert::AreEqual(250, p1.getPlayerMoney());
		}
		TEST_METHOD(BetTest)
		{
			_Player p1(1000);
			p1.Bet(250);
			Assert::AreEqual(750, p1.getPlayerMoney());
		}
		TEST_METHOD(ResetPlayer)
		{
			_Player p1(1000);
			p1.setPlayerMoney(500);
			p1.setTotalCardValue(21);
			p1.incNumOfAces(1);
			Assert::AreNotEqual(1000, p1.getPlayerMoney());
			Assert::AreNotEqual(0, p1.getTotalCardValue());
			Assert::AreNotEqual(0, p1.getNumOfAces());
			p1.resetPlayer(1000);
			Assert::AreEqual(1000, p1.getPlayerMoney());
			Assert::AreEqual(0, p1.getTotalCardValue());
			Assert::AreEqual(0, p1.getNumOfAces());
		}
	};
	TEST_CLASS(DealerTest)
	{
		TEST_METHOD(DealerInit)
		{
			_Dealer theDealer;
			Assert::AreEqual(0, theDealer.getPlayerMoney());
		}
		TEST_METHOD(DealerReceiveBet)
		{
			_Dealer theDealer;
			theDealer.Bet(100);
			Assert::AreEqual(100, theDealer.getPlayerMoney());
		}
		TEST_METHOD(ResetDealer)
		{
			_Dealer theDealer;
			theDealer.setPlayerMoney(100);
			Assert::AreNotEqual(0, theDealer.getPlayerMoney());
			theDealer.resetPlayer();
			Assert::AreEqual(0, theDealer.getPlayerMoney());
		}
	};
	TEST_CLASS(CardTest)
	{
	public:
		TEST_METHOD(Card_init_test)
		{
			_Card c1;
			Assert::IsFalse(c1.hasBeenUsed);
		}
	};

	TEST_CLASS(DeckTest)
	{
	public:
		TEST_METHOD(DeckInitTest)
		{
			_Deck deck;
			for (auto c : deck.deck)
			{
				Assert::IsNotNull(c);
			}
		}
		TEST_METHOD(PopulateDeckTest)
		{
			_Deck deck;
			deck.populate();
			for (auto c : deck.deck)
			{
				Assert::IsTrue(c->cardValue);
				Assert::IsNotNull(&c->img_loc);
			}
		}
	};

	TEST_CLASS(BlackjackgameTest)
	{
	public:
		TEST_METHOD(BlackjackgameSetBetTest)
		{
			_Blackjackgame bjg;
			int betAmount = 100000;
			bjg.set_bet_amount(betAmount);
			Assert::AreEqual(bjg.getTotalBetAmount(), 0);
			bjg.set_bet_amount(500);
			Assert::AreEqual(bjg.getTotalBetAmount(), bjg.player->getPlayerMoney());
		}
		TEST_METHOD(HitTest)
		{
			_Blackjackgame bjg;
			bjg.hit(bjg.player);
			Assert::AreNotEqual(bjg.player->getTotalCardValue(), 0);
		}
		
		TEST_METHOD(CheckWinnerTest)
		{
			_Blackjackgame bjg;
			bjg.startAnotherRound();
			bjg.hit(bjg.player);
			bjg.hit(bjg.dealer);
			bjg.winnerIsDetermined(bjg.player, bjg.dealer);
			Assert::AreNotEqual(bjg.player->getPlayerMoney(), bjg.dealer->getPlayerMoney());
		}
		
	};
}
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project1/_Card.cpp"
#include "../Project1/_Deck.cpp"
#include "../Project1/_Player.cpp"
#include "../Project1/_Blackjackgame.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Player_money_test)
		{
			// TODO: Your test code here
			_Player p1(250);
			Assert::AreEqual(250, p1.getPlayerMoney());
		}
		TEST_METHOD(Card_init_test)
		{
			// TODO: Your test code here
			_Card c1;
			Assert::IsFalse(c1.hasBeenUsed);
		}
		TEST_METHOD(Deck_init_test)
		{
			// TODO: Your test code here
			_Deck deck;
			//Assert;
		}
		TEST_METHOD(Black_Jack_Game_test)
		{
			// TODO: Your test code here
			_Blackjackgame game;
			//Assert;
		}

	};
}
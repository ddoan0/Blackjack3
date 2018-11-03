#include "pch.h"
#include "../Project1/_Player.h"

class A
{
private:
	int length;
	int width;
public:
	A() { length = 3; width = 2; };
	int getSize() { return length * width; };
};

TEST(TestCaseName, TestName) {

	A a = new A();

  EXPECT_EQ(1,1);
  EXPECT_TRUE(true);
}

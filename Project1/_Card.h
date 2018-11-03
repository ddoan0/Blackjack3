#include <string>

class _Card
{
public:
	_Card();

public:
	int cardValue;
	int aCardValue;
	std::string suit;
	std::string img_loc;
	bool hasBeenUsed;
};
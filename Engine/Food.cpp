#include "Food.h"

Food::Food(Board& brd)
{
	spawn();
}

void Food::spawn()
{	
	
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(10, 50);
	std::uniform_int_distribution<int> yDist(10, 40);

	loc = {xDist(rng), yDist(rng) };
	Eaten = false;
	//loc = { 11, 15 };
	
}
void Food::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

bool Food::willGetConsumed(const Location& head) 
{
	if (loc == head)
	{
		return true;
		Eaten = true;
	}
	else
	{
		return false;
	}
}

bool Food::isEaten() const
{
	return Eaten;
}


#pragma once
#include "Location.h"
#include"Colors.h"
#include"Board.h"
#include<random>


class Food
{
public:
	Food(Board& brd);
	void spawn();
	void Draw(Board& brd);
	bool willGetConsumed(const Location& head);
	bool isEaten() const;
	

private:
	
	Location loc;
	Color c = Colors::Red;
	bool Eaten = false;
};
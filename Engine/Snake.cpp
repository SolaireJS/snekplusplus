#include"Snake.h"
#include"assert.h"
#include<cmath>
#include<random>
Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0 ; --i) // i>0 to avoid moving head
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);

}

void Snake::Grow()
{
	if (nSegments < nSegmentMax)
	{
		segments[nSegments ].InitBody();
		nSegments++;
	}
	

	


}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::getNextHeadLocation(Location& delta_loc) const
{	
	Location loc = segments[0].getLocation();
	loc.Add(delta_loc);
	return loc;
}

bool Snake::isInTile(const Location& target) const
{
	/*return false;*/

	for (int i = 0; i < nSegments - 1  ; ++i)
	{
		// segment[0] is always the head.	
		if (segments[i].getLocation() == target)
		{
			return true;
		}
		

	}
	return false;


}


void Snake::Segment::InitHead(const Location& loc_in)
{
	loc = loc_in;												//Which assignment type is used here. 
	c = Snake::HeadColor;
}

void Snake::Segment::InitBody()
{	
	std::random_device rd;
	std::mt19937 rng(rd());
	
	std::uniform_int_distribution<int> gDist(50, 255);

	c = Color(0, gDist(rng), 0 );
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert( abs(delta_loc.x) + abs(delta_loc.y) == 1 );
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c); // does making the method const here, makes it pass loc(member of class) as const to ensure that we cannot change loc frm
						 // inside????????????
}

const Location& Snake::Segment::getLocation() const
{
	return loc;
}

int Snake::Segment::getX()
{
	return loc.x ;
}

int Snake::Segment::getY()
{
	return loc.y ;
}



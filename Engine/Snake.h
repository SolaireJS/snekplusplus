#pragma once
#include "Location.h"
#include"Colors.h"
#include"Board.h"

class Snake
{
public:
	
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd)  const;
	Location getNextHeadLocation(Location& delta_loc) const ;
	bool isInTile(const Location& target) const;
	


private:
	class Segment 
	{
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc );
		void Draw( Board& brd) const;
		const Location& getLocation() const;
		
		int getX();
		int getY();

	private:
		Location loc;  
		Color c;
	};

private:
	static constexpr Color HeadColor =  Colors::Yellow;
	static constexpr Color BodyColor =  Colors::Green;
	static constexpr int nSegmentMax = 50;

	
	Segment segments [nSegmentMax];
	int nSegments = 1;				//Points to the segment next to the last used segment.



};

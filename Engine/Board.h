#pragma once

#include "Graphics.h"
#include "Location.h"



#define CELL_DIMENSION = 20;
#define WIDTH = 10;
#define HEIGHT = 10;

class Board
{

public:
	Board(Graphics&  gfx);
	void DrawCell( const Location& loc, Color c);
	bool isInsideBoard(const Location& loc) const; 

	int getGridWidth();
	int getGridHeight();

private:
	static constexpr int dimension = 10;
	static constexpr int width = 80;
	static constexpr int height = 60;

	Graphics& gfx;


};
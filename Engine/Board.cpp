#include "Board.h"

Board::Board(Graphics& gfx_ref)
	:
	gfx(gfx_ref)
{

}


void Board::DrawCell( const Location  &loc, Color c)
{
	gfx.DrawRectDim(loc.x*dimension, loc.y*dimension, dimension, dimension, c);

}

bool Board::isInsideBoard(const Location& loc) const
{
	return (loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height);
}

int Board::getGridWidth()
{
	return width;
}

int Board::getGridHeight()
{
	return height;
}

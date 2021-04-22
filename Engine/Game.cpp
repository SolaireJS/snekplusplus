/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random> 
#include "Location.h"
#include"StaticDrawOver.h"

// Game Window is 800x600

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snek1(loc),
	food1(brd)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
	
}

void Game::UpdateModel()
{
	if (gameOver == false)
	{
		/*event handing*/
		
		// WASD controls.
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta = { 0 , -1 };
			
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))		
		{
			delta = { 0 , 1 };						//move down
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta = { -1, 0 };			
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta = { 1 , 0 };			
		}

		Location next = snek1.getNextHeadLocation(delta);
		if (!brd.isInsideBoard(next)
			|| snek1.isInTile(next))
		{
			gameOver = true;
		}

		if (food1.willGetConsumed(next))
		{
			snek1.Grow();
			snek1.MoveBy(delta);
			if (snakeMovePeriod <= 1)
			{
				snakeMovePeriod = 1;
			}
			else {
				snakeMovePeriod -= 2;
			}
			food1.spawn();
		}

		++snakeMoveCounter;
		if (snakeMoveCounter >= snakeMovePeriod)
		{
			if (wnd.kbd.KeyIsPressed(VK_CONTROL))
			{
				//snek1.Grow();
			}
			snakeMoveCounter = 0;
			snek1.MoveBy(delta);
		}
		
	}
	
	
	
}

void Game::ComposeFrame()
{
	//std::uniform_int_distribution<int> colorDist(0, 255);
	//for (int y = 0; y < brd.getGridHeight(); y++)
	//{
	//	for (int x = 0; x < brd.getGridWidth(); x++)
	//	{
	//		Location loc = { x, y };
	//		//Color c(colorDist(rng), colorDist(rng), colorDist(rng));
	//		Color c = Colors::Black;
	//		brd.DrawCell(loc, c);
	//	}
	//}

	snek1.Draw(brd);
	if (gameOver == true)
	{
		drawGameOver(300, 300, gfx);
	}
	
	if (!food1.isEaten())
	{
		food1.Draw(brd);
	}
}

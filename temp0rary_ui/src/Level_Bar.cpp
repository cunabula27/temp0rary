#include "Level_Bar.hpp"

Level_Bar::Level_Bar()
{
}

void Level_Bar::setup()
{
	path.setFillColor(70);
	path.setStrokeColor(255);
	path.setStrokeWidth(1);
	height = 2;
}


void Level_Bar::update(int x, int y, int z, int barWidth)
{
	
	path.rectangle(x, y, z, barWidth, height);
}

void Level_Bar::draw()
{
	path.draw();
	path.clear();
}

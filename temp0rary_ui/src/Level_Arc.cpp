#include "Level_Arc.hpp"

Level_Arc::Level_Arc()
{
}

void Level_Arc::setup()
{
	path.setFillColor(70);
	path.setStrokeColor(255);
	path.setStrokeWidth(1);
	path.setCircleResolution(128); 
	angleEnd = 2;
}

void Level_Arc::update(int x, int y, int z, int outerRadius, int barWidth)
{
	
	
	path.moveTo(x + outerRadius, y, z);
	path.arc(x, y, z, outerRadius, outerRadius, 0, angleEnd);
	float result = ofDegToRad(angleEnd);
	path.lineTo(x + ((outerRadius - barWidth) * cos(result)), y + ((outerRadius - barWidth) * sin(result)));
	path.arcNegative(x, y, z, (outerRadius - barWidth), (outerRadius - barWidth), angleEnd, 0);
	path.close();
}

void Level_Arc::draw()
{
	path.draw();
	path.clear();
}


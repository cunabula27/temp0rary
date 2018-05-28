#pragma once

#include "ofMain.h"

class Level_Arc
{
public:
	Level_Arc();
	
	void setup();
	void update(int x, int y, int z, int outerRadius, int barWidth);
	void draw();

	ofPath path;

	int x, y, z;		// origin point
	int outerRadius;	
	int barWidth;
	float angleEnd;

};


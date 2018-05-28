#pragma once

#include "ofMain.h"

class Level_Bar
{
public:
	Level_Bar();

	void setup();
	void update(int x, int y, int z, int barWidth);
	void draw();

	int x, y, z; // origin point (bottom left if positive is up / top right if positive is down)

	int barWidth;

	float height;

	ofPath path;
};


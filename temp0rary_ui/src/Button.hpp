#pragma once

#include "ofMain.h"

class Button
{
public:
	Button();

	void setup(int x, int y, int z, int radius);
	void setup(int x, int y, int z, int width, int height);
	void update();
	void draw();

	ofPath path;

	bool buttonOn;
};


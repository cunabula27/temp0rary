#pragma once

#include "ofMain.h"

class Bar_Line
{
public:
	Bar_Line();

	void setup();
	void update();
	void draw();

	int barLength; 
	float x;
	float y;
	float speedX;
	float lineWidth;

	ofColor colour;
};


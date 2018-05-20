#pragma once

#include "ofMain.h"

class Bar_Rect
{
public:
	Bar_Rect();

	void setup(float y,float depth);
	void update();
	void draw(float y,float depth);

	float x;
	float y;
	float width;
	float depth;
	float speedX;

	glm::vec3 topLeft;

	ofColor colour;
};


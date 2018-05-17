#pragma once

#include "ofMain.h"

class squareMask
{
public:
	void setup(vector <ofRectangle> s);
	void update(vector <ofRectangle> s);
	void draw(vector <ofRectangle> s);

	int posIndex;
	ofColor color;

	squareMask();

};


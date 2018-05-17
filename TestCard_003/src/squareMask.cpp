#include "squareMask.hpp"

squareMask::squareMask()
{
}

void squareMask::setup(vector <ofRectangle> s)
{
	posIndex = ofRandom(s.size());
}

void squareMask::update(vector <ofRectangle> s)
{
	posIndex = ofRandom(s.size());
}

void squareMask::draw(vector <ofRectangle> s)
{
	if (ofGetFrameNum() % 20 == 0)
	ofDrawRectangle(s[posIndex]);
}


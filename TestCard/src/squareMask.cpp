#include "squareMask.hpp"

squareMask::squareMask()
{
}

void squareMask::setup(vector <ofRectangle> s)
{
	colour.set(ofRandom(150,255));
	posIndex = ofRandom(s.size());
	i = colour.getBrightness();
}

void squareMask::update(vector <ofRectangle> s)
{
	//posIndex = ofRandom(s.size());
	colour.setBrightness(i--);
}

void squareMask::draw(vector <ofRectangle> s)
{
	ofSetColor(colour);
	//if (ofGetFrameNum() % 5 == 0)
	ofDrawRectangle(s[posIndex]);
}



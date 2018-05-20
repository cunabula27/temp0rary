#include "Bar_Rect.hpp"

Bar_Rect::Bar_Rect()
{
}

void Bar_Rect::setup(float y, float depth)
{
	x = ofRandom(ofGetWidth());
	width = ofRandom(200.f);
	speedX = ofRandom(-2.f, 2.f);
	colour = ofColor(ofRandom(50.f, 255.f), 128.f);

}

void Bar_Rect::update()
{
	if (x < 0) {
		x = 0;
		speedX *= -1;
	}
	else if (x > ofGetWidth()) {
		x = ofGetWidth();
		speedX *= -1;
	}
	x += speedX;
}

void Bar_Rect::draw(float y, float depth)
{
	ofSetColor(colour);
	ofDrawRectangle(x,y, width, depth);
}


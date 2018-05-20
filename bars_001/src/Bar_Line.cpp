#include "Bar_Line.hpp"

Bar_Line::Bar_Line()
{
}

void Bar_Line::setup()
{
	barLength = ofGetHeight()/*200ofRandom(10, 200)*/;
	x = ofRandom(0,ofGetWidth());
	y = 0/*ofRandom(0, ofGetHeight() - barLength)*/;
	lineWidth = ofRandom(5);
	speedX = ofRandom(-2.f, 2.f);
	colour = ofColor(255);
	ofSetColor(colour);
}

void Bar_Line::update()
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

void Bar_Line::draw()
{
	ofSetColor(colour);
	ofSetLineWidth(lineWidth);
	ofDrawLine(x, y, x, y + barLength);
}
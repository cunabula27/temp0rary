#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include <cmath>

#include "Level_Bar.hpp"
#include "Level_Arc.hpp"
#include "Button.hpp"

class ofApp : public ofBaseApp, public ofxMidiListener 
{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

		void exit();

		void newMidiMessage(ofxMidiMessage& eventArgs);

		ofxMidiIn midiIn;
		ofxMidiMessage midiMessage;

		Level_Bar Bar_1;
		Level_Bar Bar_2;

		Level_Arc Arc_1;
		Level_Arc Arc_2;

		Button CircleButton;
		Button SquareButton;
		Button RectangleButton;

		
};

#pragma once

#include "ofMain.h"
#include "squareMask.hpp"
#include "ofxSpout2Sender.h"
#include "ofxMidi.h"

#define NSQUARES 60

class ofApp : public ofBaseApp, public ofxMidiListener {

	public:
		void setup();
		void update();
		void draw();

		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void newMidiMessage(ofxMidiMessage& eventArgs);

		ofxMidiIn midiIn;
		ofxMidiMessage midiMessage;
		
		int i, j = 0;

		vector <glm::vec3> coords_100;
		vector <ofRectangle> squares;

		squareMask groupOfSquares[NSQUARES];

		ofFbo fbo;
		ofxSpout2::Sender spout;
		
};

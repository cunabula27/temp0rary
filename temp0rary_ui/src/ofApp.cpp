#include "ofApp.h"

// ---------- //

void ofApp::setup()
{
	ofBackground(0);
	ofEnableAntiAliasing();
	ofSetLogLevel(OF_LOG_VERBOSE);	// delete for release

	midiIn.openPort(2);				// VMidi 2		
	midiIn.addListener(this);		// add ofApp as a listener
	midiIn.setVerbose(true);		// delete for release - prints received messages to the console

	Arc_1.setup();
	Arc_2.setup();

	Bar_1.setup();
	Bar_2.setup();

	CircleButton.setup(400, 400, 0, 50);
	SquareButton.setup(500, 400, 0, 20, 20);
	RectangleButton.setup(600, 400, 0, 20, 40);
}

// ---------- //

void ofApp::update()
{
	Bar_1.update(400, 300, 0, 10);
	Bar_2.update(500, 300, 0, 40);

	Arc_1.update(150, 150, 0, 100, 30);
	Arc_2.update(150, 150, 0, 50, 5);

	CircleButton.update();
	RectangleButton.update();
	SquareButton.update();

}

// ---------- //

void ofApp::draw()
{
	Bar_1.draw();
	Bar_2.draw();

	Arc_1.draw();
	Arc_2.draw();

	CircleButton.draw();
	RectangleButton.draw();
	SquareButton.draw();

}

// ---------- //

void ofApp::keyPressed(int key) {
	if (key == 'x') {
		ofSaveScreen("screengrab_" + ofGetTimestampString() + ".png");
	}
}

// ---------- //

void ofApp::exit()
{
	midiIn.closePort();
	midiIn.removeListener(this);
}

// ---------- //

void ofApp::newMidiMessage(ofxMidiMessage& msg) 
{
	midiMessage = msg;	// make a copy of the latest message

	if (midiMessage.status == MIDI_CONTROL_CHANGE && midiMessage.control == 16)
	{
		// penultimate value > 0 seems to sto initialisation at max value
		// final value = max angle in degrees
		Arc_1.angleEnd = ofMap(midiMessage.value, 0, 127, 1, 359);
	}

	if (midiMessage.status == MIDI_CONTROL_CHANGE && midiMessage.control == 17)
	{
		// penultimate value > 0 seems to sto initialisation at max value
		// final value = max angle in degrees
		Arc_2.angleEnd = ofMap(midiMessage.value, 0, 127, 1, 359); 
	}

	if (midiMessage.status == MIDI_CONTROL_CHANGE && midiMessage.control == 18)
	{
		// final value = max height (negative is up)
		Bar_1.height = ofMap(midiMessage.value, 0, 127, 0, -200);
	}

	if (midiMessage.status == MIDI_CONTROL_CHANGE && midiMessage.control == 19)
	{
		// final value = max height (negative is up)
		Bar_2.height = ofMap(midiMessage.value, 0, 127, 0, -200);
	}

	if (midiMessage.channel == 1 && midiMessage.pitch == 53)
	{
		CircleButton.buttonOn = !CircleButton.buttonOn;
	}

	if (midiMessage.channel == 2 && midiMessage.pitch == 53)
	{
		SquareButton.buttonOn = !SquareButton.buttonOn;
	}

	if (midiMessage.channel == 3 && midiMessage.pitch == 53)
	{
		RectangleButton.buttonOn = !RectangleButton.buttonOn;
	}
}
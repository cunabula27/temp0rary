#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundColor(0);
	ofSetLineWidth(1);
	ofSetFrameRate(60);			// set framerate limit to 60 FPS
	
	for (int y = 0; y < ofGetHeight() + 1; y = y + 100) {
		for (int x = 0; x < ofGetWidth() + 1; x = x + 100) {
			glm::vec3 temp_pos(x - ofGetWidth() / 2, y - ofGetHeight() / 2, 0.f);
			coords_100.push_back(temp_pos);
		}
	}

	for (int i = 0; i < coords_100.size() - (ofGetWidth() / 100 + 2); i++) {
		if ((i + 1) % ((ofGetWidth() / 100) + 1) != 0) {
			ofRectangle a(coords_100[i], coords_100[i + 2 + (ofGetWidth() / 100)]);
			squares.push_back(a);
		}
	}
	for (int i = 0; i < NSQUARES; i++)
	{
		groupOfSquares[i].setup(squares);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < NSQUARES; i++)
	{
		groupOfSquares[i].update(squares);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	ofSetColor(150);	// set colour

	for (int i = 0; i < NSQUARES; i++)
	{
		groupOfSquares[i].draw(squares);
	}

	//if (ofGetFrameNum() % 20 == 0)						// slow down squares firing
	//{
	//	int b = ofRandom(squares.size());				// random square fires
	//	ofDrawRectangle(squares[b]);
	//}

											// set colour

	for (int i = 0; i < coords_100.size(); i++)			// draw ticks code starts
	{
		ofSetColor(50);
		auto pos = coords_100[i];
		ofDrawLine(pos.x - 6, pos.y, pos.x + 6, pos.y);
		ofDrawLine(pos.x, pos.y - 6, pos.x, pos.y + 6);
	}													// draw ticks code ends

										// set colour
	
	ofPushMatrix();										// inner dial
	for (int r = 0; r < j; r++)
	{
		ofSetColor(250);
		ofDrawLine(150, 0, 190, 0);
		ofRotateDeg(7.5);
	}
	ofPopMatrix();

										// set colour

	ofPushMatrix();										// outer dial
	for (int r = 0; r < i; r++)
	{
		ofSetColor(200);
		ofDrawLine(210, 0, 240, 0);
		ofRotateDeg(7.5);
	}
	ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
	switch (key)
	{
	case OF_KEY_UP:
		i++;
		break;
	case OF_KEY_DOWN:
		i--;
		break;
	case OF_KEY_LEFT:
		j++;
		break;
	case OF_KEY_RIGHT:
		j--;
		break;
	case 's':
		ofSaveScreen("screengrab_" + ofGetTimestampString() + ".png");
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	if (button==0)
	{
		for (int i = 0; i < NSQUARES; i++)
		{
			groupOfSquares[i].setup(squares);
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	//coords_100.clear();
	//squares.clear();
	//for (int y = 0; y < ofGetHeight() + 1; y = y + 100) {
	//	for (int x = 0; x < ofGetWidth() + 1; x = x + 100) {
	//		glm::vec3 temp_pos(x - ofGetWidth() / 2, y - ofGetHeight() / 2, 0.f);
	//		coords_100.push_back(temp_pos);
	//	}
	//}

	//for (int i = 0; i < coords_100.size() - (ofGetWidth() / 100 + 2); i++) {
	//	if ((i + 1) % ((ofGetWidth() / 100) + 1) != 0) {
	//		ofRectangle a(coords_100[i], coords_100[i + 2 + (ofGetWidth() / 100)]);
	//		squares.push_back(a);
	//	}
	//}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

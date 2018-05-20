#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetBackgroundColor(0);
	y = ofRandom(ofGetHeight());
	depth = ofRandom(ofGetHeight() - y);
	
	for (int i = 0; i < NBARS; i++) 
	{ 
		groupOfBarsL[i].setup(); 
		groupOfBarsR[i].setup(y, depth);
	}
	fbo.allocate(ofGetWidth(), ofGetHeight());
	//bool doSaveScreen = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofClear(0, 0, 0, 255);
	for (int i = 0; i < NBARS; i++) 
	{ 
		groupOfBarsL[i].update(); 
		groupOfBarsR[i].update();
	}
	
	/*if (doSaveScreen)
	{
		ofSaveScreen(ofToString(ofGetFrameNum()) + ".png");
		doSaveScreen = false;
	}*/
	
	spout.sendTexture(fbo.getTexture(), "composition");
}

//--------------------------------------------------------------
void ofApp::draw(){
	fbo.begin();
	ofClear(0, 0, 0, 255);
	for (int i = 0; i < NBARS; i++) 
	{ 
		groupOfBarsL[i].draw(); 
		groupOfBarsR[i].draw(y, depth);
	}
	fbo.end();
	fbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	switch (key)
	{
	case 's':
		ofSaveScreen("screengrab_" + ofGetTimestampString() + ".png");
		break;
	case 'd':
		depth = ofRandom(ofGetHeight() - y);
		break;
	case 'y':
		y = ofRandom(ofGetHeight());
		break;
	//case 'm':
	//	doSaveScreen = true;
	//	break;
	}
}
void ofApp::exit() {
	spout.exit();
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

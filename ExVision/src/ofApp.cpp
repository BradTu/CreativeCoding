//Made by Brad Tully
//9 May 2016
//Creative Coding Exercise Vision
//This program uses the computer's camera. It draws a pair of sunglasses on the user's eyes and if they open their
//mouth it draws circles that fall out of their mouth. This uses the addons ofxBox2d, ofxCv, ofxFaceTracker, ofxGui,
//ofxOpenCv, ofxOsc, and ofxXmlSettings

#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup() {
	//Set up the camera and the face tracker
	camera.initGrabber(520, 400);
	tracker.setup();
	camera.setDesiredFrameRate(60.0);

	//Set up ofBox2d 
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createBounds();
	box2d.setFPS(60.0);
}

//--------------------------------------------------------------
void ofApp::update() {
	//Update the camera
	camera.update();
	if (camera.isFrameNew()) {
		tracker.update(toCv(camera));
	}

	distance = tracker.getImagePoint(64).y - tracker.getImagePoint(61).y;

	//Update box2d
	box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	//Draw the image
	camera.draw(0, 0);
	ofSetColor(255);

	//Draws sunglasses on the user
	ofSetColor(0);
	ofDrawRectangle(tracker.getImagePoint(36).x - 25, tracker.getImagePoint(39).y - 25, 60, 60);
	ofDrawRectangle(tracker.getImagePoint(45).x - 25, tracker.getImagePoint(42).y - 25, 60, 60);
	ofSetLineWidth(10);
	ofDrawLine(tracker.getImagePoint(36).x - 25, tracker.getImagePoint(39).y,
		tracker.getImagePoint(45).x - 25, tracker.getImagePoint(42).y);
	ofSetColor(255);

	//Draw wire frame on face
	/*ofSetLineWidth(1);
	tracker.getImageMesh().drawWireframe();
	tracker.draw(true);*/

	ofDrawBitmapString(distance, 20, 20);

	if ((tracker.getImagePoint(64).y - tracker.getImagePoint(61).y) >= 16) {
		float r = ofRandom(4, 20);
		circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
		circles.back().get()->setPhysics(3.0, 0.53, 0.1);
		circles.back().get()->setup(box2d.getWorld(), tracker.getImagePoint(64).x, tracker.getImagePoint(64).y, 10);
	}

	for (int i = 0; i<circles.size(); i++) {
	ofFill();
	ofSetHexColor(0xf6c738);
	circles[i].get()->draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 't') ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

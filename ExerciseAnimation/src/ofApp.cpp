#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(30);
	ofLog() << "Click the mouse on screen to start a new game.";
	ofLog() << "Player one controls using the w and s keys.";
	ofLog() << "Player two controls using the up and down keys.";
	
	//Sets the parameters of the circle
	xCircle = 300;
	yCircle = 300;
	circleXVel = 10;
	circleYVel = 8;

	//Sets the parameters of player one
	xOne = 0;
	yOne = 300;
	oneXVel = 0;
	oneYVel = 0;
	oneScore = 0;

	//Sets the parameters of player two
	xTwo = 590;
	yTwo = 300;
	twoXVel = 0;
	twoYVel = 0;
	twoScore = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	//Updates the circle's position
	xCircle = xCircle + circleXVel;
	yCircle = yCircle + circleYVel;

	//Updates player one's position
	xOne = xOne + oneXVel;
	yOne = yOne + oneYVel;

	//Updates player two's position
	xTwo = xTwo + twoXVel;
	yTwo = yTwo + twoYVel;

	//Keeps the ball in the frame and keeps track of the score
	if (xCircle >= 600) {
		circleXVel = -1 * circleXVel;
		oneScore++;
	}
	if (xCircle <= 0) {
		circleXVel = -1 * circleXVel;
		twoScore++;
	}
	if (yCircle >= 600 || yCircle <= 0) {
		circleYVel = -1 * circleYVel;
	}

	//Changes the direction of the circle when it interacts with the players one, two
	if (xCircle - 15 <= xOne + 10 && xCircle + 15 >= xOne - 10 && 
		yCircle + 15 >= yOne - 50 && yCircle - 15 <= yOne + 10) {
		circleXVel = -1 * circleXVel;
	}
	else if (xCircle + 15 >= xTwo - 10 && xCircle - 15 <= xTwo + 10 &&
		yCircle + 15 >= yTwo - 50 && yCircle - 15 <= yTwo + 10) {
		circleXVel = -1 * circleXVel;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Draws the ball object
	ofSetColor(189, 22, 245);
	ofDrawCircle(xCircle, yCircle, 15);

	ofRectMode(OF_RECTMODE_CENTER);

	//Draws player one
	ofSetColor(230, 21, 69);
	ofDrawRectangle(xOne, yOne, 10, 50);

	//Draws player two
	ofSetColor(31, 186, 194);
	ofDrawRectangle(xTwo, yTwo, 10, 50);

	//Prints the score to the canvas
	ofSetColor(230, 21, 69);
	ofDrawBitmapString(oneScore, 100, 50);
	ofSetColor(31, 186, 194);
	ofDrawBitmapString(twoScore, 500, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//Moves player one up and down
	if (key == 'w') {
		oneYVel = -10;
	}
	if (key == 's') {
		oneYVel = 10;
	}

	//Moves player two up and down
	if (key == OF_KEY_UP) {
		twoYVel = -10;
	}
	if (key == OF_KEY_DOWN) {
		twoYVel = 10;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	//Stops player one when the key isn't pressed
	if (key == 'w') {
		oneYVel = 0;
	}
	if (key == 's') {
		oneYVel = 0;
	}

	//Stops player two when the key isn't pressed
	if (key == OF_KEY_UP) {
		twoYVel = 0;
	}
	if (key == OF_KEY_DOWN) {
		twoYVel = 0;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	setup();
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

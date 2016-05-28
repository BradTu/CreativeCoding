#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//Setup the background and initialize the money amount and rig amount
	ofSetBackgroundColor(237, 225, 130);
	money = 50;
	rigNum = 0;
	bribe = false;
	corruption = false;
	ofSetFrameRate(10);
	ofSetCircleResolution(100);

	//Make the oil patch objects
	for (int i = 0; i < 15; i++) {
		oil[i].setX(ofRandom(50, 1180));
		oil[i].setY(ofRandom(50, 620));
		oil[i].setRadius(ofRandom(20, 60));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	//Update the size of the oil patch and the money amount
	for (int i = 0; i < 15; i++) {
		if (oil[i].isRigged() == true && oil[i].consuming() == true) {
			oil[i].consuming();
			money = money + 20;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Draw the lines on the canvas
	ofSetColor(0);
	ofDrawLine(600, 0, 600, 650);
	ofDrawLine(600, 325, 1200, 325);

	//Draw the oil patches
	for (int i = 0; i < 15; i++) {
		oil[i].draw();
	}

	//Draw the oil rigs
	for (int i = 0; i <= rigNum; i++) {
		rig[i].draw();
		ofSetColor(137, 143, 145);
	}

	//Set the rectangle mode to center and set the color to green
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(43, 189, 60);

	//Rig button
	ofDrawRectangle(560, 640, 75, 25);

	//Bribe button
	ofDrawRectangle(1140, 310, 120, 25);

	//Coup button
	ofDrawRectangle(1140, 640, 120, 25);

	//Labels for buttons and regions of the map and money count
	ofSetColor(255, 0, 0);
	ofDrawBitmapString("$", 283, 20);
	ofDrawBitmapString(money, 290, 20);
	ofDrawBitmapString("Rig $50", 533, 643);
	ofDrawBitmapString("Nature Reservation", 880, 20);
	ofDrawBitmapString("Seperate Nation", 910, 345);
	ofDrawBitmapString("Bribe $1000", 1100, 315);
	ofDrawBitmapString("Coup $2000", 1100, 645);
	ofSetRectMode(OF_RECTMODE_CORNER);

	//When the player completes the game
	if (rigNum == 15) {
		ofSetColor(0, 0, 255);
		ofDrawBitmapString("Congrats you won! But we all lose because a ton of CO2 that was in the ground is now in the atmosphere and is altering the climate.", 
			                97, 250);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	//Test whether the oil is clicked
	for (int i = 0; i < 15; i++) {
		oil[i].isClicked(x, y);
	}
	
	//Is the purchase button pressed
	if (x <= 560 + 37.5 && x >= 560 - 37.5 && y <= 640 + 12.5 && y >= 640 - 12.5) {
		ofLog() << "Clicked the button";
		rig[rigNum].buy(true);
	}

	//Is the bribe button pressed
	if (x <= 1140 + 60 && x >= 1140 - 60 && y <= 310 + 12.5 && y >= 310 - 12.5 && bribe == false) {
		bribe = true;
		money = money - 1000;
	}

	//Is the coup button pressed
	if (x <= 1140 + 60 && x >= 1140 - 60 && y <= 640 + 12.5 && y >= 640 - 12.5 && corruption == false) {
		corruption = true;
		money = money - 2000;
	}

	//Determine if the oil is in the nature preservation
	if (x >= 600 && x <= 1200 && y >= 0 && y <= 325 && bribe == false) {
		ofLog() << "You must bribe local officials to build a rig here.";
	}

	//Determine if the oil is in the other country
	else if (x >= 600 && x <= 1200 && y >= 325 && y <= 650 && corruption == false) {
		ofLog() << "You must throw a government coup to build a rig here.";
	}

	//Purchase and build the rig
	else if (rig[rigNum].buy() == true) {
		money = money - 50;
		for (int j = 0; j < 15; j++) {
			if (oil[j].isClicked(x, y) == true) {
				rig[rigNum] = Rig(oil[j].getX(), oil[j].getY());
				oil[j].isRigged(rig[rigNum]);
				rigNum++;
			}
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//-------------------------------------------------------------------------------------------------------------------
//Rig class methods

//Rig argument constructor
ofApp::Rig::Rig(int theX, int theY) {
	x = theX;
	y = theY;
	width = 30;
	height = 30;
	tF = false;
}

//Rig no argument constructor
ofApp::Rig::Rig() {

}

//Tells whether or not a rig was purchased
bool ofApp::Rig::buy(bool val) {
	tF = val;
	return val;
}

//No arguments
bool ofApp::Rig::buy() {
	return tF;
}

//Draws the oil rig
void ofApp::Rig::draw() {
	ofSetColor(219, 165, 18);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawRectangle(x, y, width, height);
	ofSetRectMode(OF_RECTMODE_CORNER);
}

//Returns the rig's x position
int ofApp::Rig::getX() {
	return x;
}

//Returns the rig's y position
int ofApp::Rig::getY() {
	return y;
}

//Set the x value
void ofApp::Rig::setX(int theX) {
	x = theX;
}

//Set the y value
void ofApp::Rig::setY(int theY) {
	y = theY;
}

//Set the width
void ofApp::Rig::setWidth(int theWidth) {
	width = theWidth;
}

//Set the height
void ofApp::Rig::setHeight(int theHeight) {
	height = theHeight;
}


//-----------------------------------------------------------------------------------------------------------------
//OilPatch class methods

//OilPatch argument constructor
ofApp::OilPatch::OilPatch(int theX, int theY, int rad) {
	x = theX;
	y = theY;
	radius = rad;
}

//OilPatch no argument constructor
ofApp::OilPatch::OilPatch() {
	
}

//Tells whether or not the oil patch has a rig on it
bool ofApp::OilPatch::isRigged(Rig theRig) {
	if (theRig.getX() == x && theRig.getY() == y) {
		trueFalse = true;
	}
	else {
		trueFalse = false;
	}
	return trueFalse;
}

//No arguments
bool ofApp::OilPatch::isRigged() {
	return trueFalse;
}

//Reduces the size of the oil patch as it is consumed by the rig and returns true if it is, else false
bool ofApp::OilPatch::consuming() {
	if (radius >= 1) {
		radius = radius - .001;
		return true;
	}
	else {
		return false;
	}
}

//Draws an oil patch
void ofApp::OilPatch::draw() {
	ofSetColor(0);
	ofDrawCircle(x, y, radius);
}

//Tells whether or not an oil patch was pressed
bool ofApp::OilPatch::isClicked(int mouseX, int mouseY) {
	if (mouseX <= x + radius && mouseX >= x - radius &&
		mouseY <= y + radius && mouseY >= y - radius) {
		ofLog() << "Oil is pressed";
		return true;
	}
	else {
		return false;
	}
}

//Tells whether to oil is on the preserved land
bool ofApp::OilPatch::isOnPreservation() {
	bool tof;
	if (x >= 600 && x <= 1200 && y >= 0 && y <= 325) {
		tof = true;
	}
	else {
		tof = false;
	}
	return tof;
}

//Returns the oil patch's x position
int ofApp::OilPatch::getX() {
	return x;
}

//Returns the oil patch's y position
int ofApp::OilPatch::getY() {
	return y;
}

//Set the x value
void ofApp::OilPatch::setX(int theX) {
	x = theX;
}

//Set the y value
void ofApp::OilPatch::setY(int theY) {
	y = theY;
}

//Set the radius value
void ofApp::OilPatch::setRadius(int rad) {
	radius = rad;
}

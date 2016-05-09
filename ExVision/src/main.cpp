//Made by Brad Tully
//9 May 2016
//Creative Coding Exercise Vision
//This program uses the computer's camera. It draws a pair of sunglasses on the user's eyes and if they open their
//mouth it draws circles that fall out of their mouth. This uses the addons ofxBox2d, ofxCv, ofxFaceTracker, ofxGui,
//ofxOpenCv, ofxOsc, and ofxXmlSettings

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
	ofSetupOpenGL(520, 400, OF_WINDOW);			// <-------- setup the GL context

												// this kicks off the running of my app
												// can be OF_WINDOW or OF_FULLSCREEN
												// pass in width and height too:
	ofRunApp(new ofApp());

}

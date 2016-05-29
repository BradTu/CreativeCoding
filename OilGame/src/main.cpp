//Made by Brad Tully
//Creative Coding
//5/29/2016
//This program makes a basic game where the player purchases oil rigs and puts them on oil patches to make money. In order to win the 
//player must take part in activities such as bribery and paying for a government coup. This is more of a statement piece.

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1200,650,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}

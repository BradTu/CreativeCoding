// Made by Brad Tully
// 29 March 2016
// Assignment 1: Face
// This program makes a picture of Rick Sanchez from the TV show Rick and Morty
// Release the mouse on the canvas and the x and y coordinates will be printed on the console
// Press the 1-3 keys for Rick to say something on the console

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(500,500,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}

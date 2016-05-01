//Made by Brad Tully
//Creative Coding
//27 April 2016
//Project 1: ExoPlanetaryNeighborhood
/* This program displays data from NASA's Kepler program. It draws planets on the canvas with their unique
   values and returns them when clicked on. Each planet is drawn at a distance from the center in parsecs
   and its radius is based on earth radii. The color of the planet is scaled from red (hottest) to
   blue (coldest).This uses the addons ofxCsv and ofxGui. The data is read from a csv file. This program
   uses openFrameworks software which runs using c++.*/

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(600,600,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}

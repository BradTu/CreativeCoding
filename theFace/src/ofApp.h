// Made by Brad Tully
// 29 March 2016
// Assignment 1: Face
// This program makes a picture of Rick Sanchez from the TV show Rick and Morty
// Release the mouse on the canvas and the x and y coordinates will be printed on the console
// Press the 1-3 keys for Rick to say something on the console


#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};

//Brad Tully
//April 4 2016
//This app makes a two player pong style game

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
		
		//The parameters for the circle object
		float xCircle, yCircle;
		float circleXVel, circleYVel;

		//The parameters for player one
		float xOne, yOne;
		float oneXVel, oneYVel;
		float oneScore;

		//The parameters for player two
		float xTwo, yTwo;
		float twoXVel, twoYVel;
		float twoScore;
};

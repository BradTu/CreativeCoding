//Brad Tully
//5 April 2016
//Exercise 3

#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

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
		
		ofxBox2d                               box2d;   // the box2d world
		vector   <shared_ptr<ofxBox2dCircle> > circles; // default box2d circles
		vector   <shared_ptr<ofxBox2dRect> >   boxes;   // defalut box2d rects

		ofxFloatSlider radius;
		ofxPanel gui;
};
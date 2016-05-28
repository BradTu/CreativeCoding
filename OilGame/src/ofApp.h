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

		//------------------------------------------------------------------------------------------------------------
		//Rig class
		class Rig {
				int x, y, width, height, money;
				bool tF;
			public:
				Rig(int theX, int theY);
				Rig();
				bool buy(bool val);
				bool buy();
				void draw();
				int getX();
				int getY();
				void setX(int theX);
				void setY(int theY);
				void setWidth(int theWidth);
				void setHeight(int theHeight);
		};
		
		//------------------------------------------------------------------------------------------------------------
		//OilPatch class
		class OilPatch {
			int x, y, radius;
			bool trueFalse;
		public:
			OilPatch(int theX, int theY, int rad);
			OilPatch();
			bool isRigged(Rig theRig);
			bool isRigged();
			bool consuming();
			void draw();
			bool isClicked(int mouseX, int mouseY);
			bool isOnPreservation();
			int getX();
			int getY();
			void setX(int theX);
			void setY(int theY);
			void setRadius(int rad);
		};
		//-------------------------------------------------------------------------------------------------------------

		int money;
		int rigNum;

		bool bribe;
		bool corruption;

		OilPatch oil[15];
		Rig rig[15];
};

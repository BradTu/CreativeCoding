//Made by Brad Tully
//Creative Coding
//27 April 2016
//Project 1: ExoPlanetaryNeighborhood
/* This program displays data from NASA's Kepler program. It draws planets on the canvas with their unique
    values and returns them when clicked on. Each planet is drawn at a distance from the center in parsecs
	and its radius is based on earth radii. The color of the planet is scaled from red (hottest) to 
	blue (coldest). This uses the addons ofxCsv and ofxGui. The data is read from a csv file. This program
	uses openFrameworks software which runs using c++.*/

#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <fstream>
#include <cstdlib>
#include "ofxCsv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mouseScrolled(int x, int y, float scrollX, float scrollY);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int ang = 0;
		int radius;
		int centerX;
		int centerY;

		//Creates the gui panel and sliders
		ofxFloatSlider xAxis;
		ofxFloatSlider yAxis;
		ofxFloatSlider zoom;
		ofxPanel gui;

		//Variables for data extraction
		float eM, tem, oP, dFS, sN, dFE, eR;
		string pN;

		//Planet class makes planet objects (circles) and stores their values from the data file
		class Planet {
			string planetName;
			float earthMasses, temperature, orbitalPeriod, distanceFromStar, systemNumber, x, y, angle, distFromEarth, 
				  earthRadii;
		public:
			Planet(string name, double mass, float rad, double temp, 
				   double period, double dist, double system, double dFromE, double a);
			Planet();
			void setSystemNumber(int number);
			float getDistanceFromEarth();
			string getPlanetName();
			float getEarthMasses();
			float getEarthRadii();
			float getTemperature();
			float getOrbitalPeriod();
			float getDistanceFromStar();
			void setAngle(float a);
			void drawPlanet();
			void isClicked(int mouseX, int mouseY, int button);
		};

		//Creates an object to be able to read a csv file
		ofxCsv csv;
		ofxCsv csvRecorder;
		ofxCsvRow row;
		
		double earthRadius = 6371;
		double earthMass = 5.972 * pow(10, 24);

		//Makes an array of planets
		Planet thePlanets[153];

		//Makes Earth in the center of the canvas
		Planet earth = Planet("Earth", 1, 1, 289.15, 365, 1, 1, 0, 0);
};



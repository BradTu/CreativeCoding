//Made by Brad Tully
//Creative Coding
//27 April 2016
//Project 1: ExoPlanetaryNeighborhood
/* This program displays data from NASA's Kepler program. It draws planets on the canvas with their unique
   values and returns them when clicked on. Each planet is drawn at a distance from the center in parsecs
   and its radius is based on earth radii. The color of the planet is scaled from red (hottest) to
   blue (coldest). This uses the addons ofxCsv and ofxGui. The data is read from a csv file. This program
   uses openFrameworks software which runs using c++.*/

#include "ofApp.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSliderGroup.h"



//--------------------------------------------------------------
void ofApp::setup(){
	//Make the background and set resolution of circles
	ofSetCircleResolution(100);
	ofBackground(0);
	centerX = 300;
	centerY = 300;

	//Initialize center of screen and zoom
	xAxis = 0;
	yAxis = 0;
	zoom = 1;

	//Make the gui
	gui.setup();
	gui.add(xAxis.setup("X Axis", 0, -3000, 3000));
	gui.add(yAxis.setup("Y Axis", 0, -3000, 3000));
	gui.add(zoom.setup("Zoom", 1, 1, 100));

	//Load the file with the planet info and safe it to an array of planet objects
	if (csv.load("KeplerPlanets.csv")) {
		for (int i = 0; i < csv.getNumRows(); i++){
			ang = ang + 17;
				row = csv.getRow(i);
				sN = row.getInt(0);
				dFE = row.getFloat(1);
				pN = row.getString(2);
				eM = row.getFloat(3);
				if (eM == 0) {
					eM = 0;
				}
				eR = row.getFloat(4);
				if (eR == 0) {
					eR = 1;
				}
				tem = row.getFloat(5);
				if (tem == 0) {
					tem == 0;
				}
				oP = row.getFloat(6);
				dFS = row.getFloat(7);
				if (dFS == 0) {
					dFS = 0;
				}
				thePlanets[i] = Planet(pN, eM, eR, tem, oP, dFS, sN, dFE, ang);
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Draws the canvas, background, and planets as well as the gui and changes the zoom, and x y positions
	ofPushMatrix();
	ofTranslate(300, 300);
	ofTranslate(xAxis, yAxis);
	ofScale(zoom, zoom);
	ofNoFill();
	ofSetColor(255);
	radius = 0;
	for (int i = 0; i < 30; i++) {
		radius = radius + 100;
		ofDrawCircle(0, 0, radius);
		ofDrawBitmapString(radius, -10, -radius);
		ofDrawBitmapString(radius, radius, 0);
		ofDrawBitmapString(radius, -radius, 0);
		ofDrawBitmapString(radius, -10, radius);
	}
	ofFill();
	earth.drawPlanet();
	for (int b = 0; b < 153; b++) {
		thePlanets[b].drawPlanet();
	}
	ofPopMatrix();
	gui.draw();
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

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY) {
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//Determines if a planet is pressed and calls the isClicked method
	earth.isClicked((x - 300 - xAxis) / zoom, (y - 300 - yAxis) / zoom, button);
	for (int b = 0; b < csv.getNumRows(); b++) {
		thePlanets[b].isClicked((x - 300 - xAxis) / zoom, (y - 300 - yAxis) / zoom, button);
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

//PLANET CLASS methods
//Planet argument constructor
ofApp::Planet::Planet(string name, double mass, float rad, 
	                  double temp, double period, double dist, double system, double dFromE, double a)
{
	planetName = name;
	earthMasses = mass;
	earthRadii = rad;
	temperature = temp;
	orbitalPeriod = period;
	distanceFromStar = dist;
	distFromEarth = dFromE;
	systemNumber = system;
	angle = a;
	x = distFromEarth * cos(angle * (PI / 180));
	y = distFromEarth * sin(angle * (PI / 180));
}

//Planet no argument constructor
ofApp::Planet::Planet() {

}

//Sets the system number
void ofApp::Planet::setSystemNumber(int number) {
	systemNumber = number;
}

//returns the distance from earth
float ofApp::Planet::getDistanceFromEarth() {
	return distFromEarth;
}

//returns the planet name
string ofApp::Planet::getPlanetName() {
	return planetName;
}

//returns the earth masses
float ofApp::Planet::getEarthMasses() {
	return earthMasses;
}

//returns the earth radii
float ofApp::Planet::getEarthRadii() {
	return earthRadii;
}

//returns the temperature
float ofApp::Planet::getTemperature() {
	return temperature;
}

//returns the orbital period
float ofApp::Planet::getOrbitalPeriod() {
	return orbitalPeriod;
}

//Returns semi-major axis aka distance from star
float ofApp::Planet::getDistanceFromStar() {
	return distanceFromStar;
}

//Sets the angle
void ofApp::Planet::setAngle(float a) {
	angle = a;
}

//Draws an individual planet
void ofApp::Planet::drawPlanet() {
	ofSetColor((temperature * 0.115), 0, (255 - (temperature * 0.115)));
	ofDrawCircle(x, y, earthRadii * 2);
}

//Determines whether or not a planet was pressed and prints out its values to the console
void ofApp::Planet::isClicked(int mouseX, int mouseY, int button) {
	if (mouseX < x + earthRadii * 2 && mouseX > x - earthRadii * 2 &&
		mouseY < y + earthRadii * 2 && mouseY > y - earthRadii * 2) {
		ofLog() << " ";
		ofLog() << "Name: " << planetName;
		ofLog() << "Earth Masses: " << earthMasses;
		ofLog() << "Earth Radii: " << earthRadii;
		ofLog() << "Temperature: " << temperature << " Kelvin";
		ofLog() << "Orbital Period: " << orbitalPeriod << " days";
		ofLog() << "Semi-Major Axis: " << distanceFromStar << " AU";
		ofLog() << "Distance From Earth: " << distFromEarth << " parsecs";
	}
}
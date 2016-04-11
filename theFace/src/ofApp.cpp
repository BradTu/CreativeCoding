#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLog() << "Pres 1, 2, or 3 for Rick to say something on the console.";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	int white = 255;
	int black = 0;
	ofColor hairBlue = (135, 217, 245);
	ofColor skinGrey = (201, 211, 215);
	ofBackground(white);

	//Draws the hair
	ofSetColor(black);
	ofNoFill();
	ofSetLineWidth(2);
	ofBeginShape();
		ofVertex(195, 377);
		ofVertex(195, 377);
		ofVertex(152, 382);
		ofVertex(164, 361);
		ofVertex(111, 344);
		ofVertex(137, 306);
		ofVertex(95, 253);
		ofVertex(121, 226);
		ofVertex(88, 162);
		ofVertex(143, 147);
		ofVertex(118, 81);
		ofVertex(167, 92);
		ofVertex(188, 19);
		ofVertex(240, 67);
		ofVertex(283, 30);
		ofVertex(315, 104);
		ofVertex(389, 116);
		ofVertex(367, 187);
		ofVertex(407, 226);
		ofVertex(372, 267);
		ofVertex(412, 300);
		ofVertex(353, 330);
		ofVertex(360, 359);
		ofVertex(312, 365);
		ofVertex(312, 365);
	ofEndShape(true);
	
	ofSetColor(157, 223, 245);
	ofFill();
	ofBeginShape();
		ofVertex(195, 377);
		ofVertex(195, 377);
		ofVertex(152, 382);
		ofVertex(164, 361);
		ofVertex(111, 344);
		ofVertex(137, 306);
		ofVertex(95, 253);
		ofVertex(121, 226);
		ofVertex(88, 162);
		ofVertex(143, 147);
		ofVertex(118, 81);
		ofVertex(167, 92);
		ofVertex(188, 19);
		ofVertex(240, 67);
		ofVertex(283, 30);
		ofVertex(315, 104);
		ofVertex(389, 116);
		ofVertex(367, 187);
		ofVertex(407, 226);
		ofVertex(372, 267);
		ofVertex(412, 300);
		ofVertex(353, 330);
		ofVertex(360, 359);
		ofVertex(312, 365);
		ofVertex(312, 365);
	ofEndShape(true);

	//Draws the head
	ofSetCircleResolution(50);
	ofNoFill();
	ofSetLineWidth(2);
	ofSetColor(black);
	ofDrawEllipse(250, 250, 200, 300);
	ofFill();
	ofSetLineWidth(1);
	ofSetColor(skinGrey);
	ofDrawEllipse(250, 250, 200, 300);

	//Draws the eyes
	ofSetColor(black);
	ofNoFill();
	ofDrawCircle(205, 220, 40);
	ofDrawCircle(295, 220, 40);
	ofFill();
	ofSetColor(white);
	ofDrawCircle(205, 220, 40);
	ofDrawCircle(295, 220, 40);
	ofSetColor(black);
	ofDrawCircle(205, 220, 5);
	ofDrawCircle(295, 220, 5);

	//Draws the nose using a bezier
	ofNoFill();
	ofDrawBezier(240, 260, 250, 350, 260, 260, 260, 260);

	//Draws the mouth
	ofDrawBezier(205, 340, 250, 335, 295, 340, 295, 340);
	ofDrawBezier(200, 330, 195, 340, 200, 350, 200, 350);
	ofDrawBezier(300, 330, 305, 340, 300, 350, 300, 350);
	
	//Draws the eye brow
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawRectRounded(250, 170, 150, 10, 5);
	ofSetColor(157, 223, 245);
	ofDrawRectRounded(250, 170, 149, 9, 4.5);
	ofSetColor(black);
	ofDrawLine(200, 155, 300, 155);
	ofDrawLine(210, 145, 290, 145);
	
	//Draws the slobber on his mouth
	ofNoFill();
	ofSetColor(black);
	ofBeginShape();
		ofCurveVertex(232, 338);
		ofCurveVertex(232, 338);
		ofCurveVertex(228, 349);
		ofCurveVertex(249, 360);
		ofCurveVertex(263, 378);
		ofCurveVertex(281, 361);
		ofCurveVertex(275, 339);
		ofCurveVertex(275, 339);
	ofEndShape(true);
	
	ofFill();
	ofSetColor(166, 245, 210);
	ofBeginShape();
		ofCurveVertex(232, 338);
		ofCurveVertex(232, 338);
		ofCurveVertex(228, 349);
		ofCurveVertex(249, 360);
		ofCurveVertex(263, 378);
		ofCurveVertex(281, 361);
		ofCurveVertex(275, 339);
		ofCurveVertex(275, 339);
	ofEndShape(true);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '1'){
		ofLog() << "Wubba lubba dub-dub!";
	}
	if (key == '2') {
		ofLog() << "Let's get schwifty! Yeahhhh!";
	}
	if (key == '3') {
		ofLog() << "Let's get riggity wrecked!";
	}
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

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	ofLog() << x << " , " << y;
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

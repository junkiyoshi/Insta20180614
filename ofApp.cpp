#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	ofColor colors[] = { ofColor(200, 39, 39), ofColor(39, 39, 200) };
	for (int radius = 50; radius < 350; radius += 15) {

		int deg_start = ofNoise(ofGetFrameNum() * 0.01 + radius * 0.005) * 720;
		for (int i = 0; i < 2; i++) {

			ofSetColor(colors[i]);

			ofBeginShape();
			for (int deg = deg_start + i * 180; deg < deg_start + i * 180 + 90; deg += 1) {

				ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			}
			ofEndShape();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
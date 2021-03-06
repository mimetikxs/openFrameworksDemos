#include "ofApp.h"

void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(0);

	for(int i = 0; i < 1024; i++) {
		particles.push_back(Particle(ofRandomWidth(), ofRandomHeight()));
	}

	forces.push_back(ofPtr<Force>(new ForceFriction(-.01)));

	/*
	int w = ofGetWidth(), h = ofGetHeight();
	forces.push_back(ofPtr<Force>(new FieldDonut(w / 2, h / 2, w / 6, -.01, 10)));
	forces.push_back(ofPtr<Force>(new FieldLine(ofVec2f(0, h / 2), ofVec2f(w, h / 2), -.01, 10)));
	*/

	for(int i = 0; i < 16; i++) {
		ofVec2f begin(ofRandomWidth(), ofRandomHeight());
		ofVec2f end = begin + ofVec2f(ofRandomf(), ofRandomf()) * 500;
		float radius = ofRandom(5, 50);
		float magnitude = ofRandom(-2, +2);
		forces.push_back(ofPtr<Force>(new ForceLine(begin, end, radius, magnitude)));
	}

	for(int i = 0; i < 16; i++) {
		float x = ofRandomWidth(), y = ofRandomHeight();
		float radius = ofRandom(10, 200), magnitude = ofRandom(-2, +2);
		forces.push_back(ofPtr<Force>(new ForceCircle(x, y, radius, magnitude)));
	}
	
	for(int i = 0; i < particles.size(); i++) {
		for(int j = 0; j < forces.size(); j++) {
			particles[i].addForce(forces[j]);
		}
	}
}

void ofApp::update() {
	for(int i = 0; i < particles.size(); i++) {
		particles[i].update(1);
	}
}

void ofApp::draw() {
	ofSetColor(255);
	for(int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
	for(int i = 0; i < forces.size(); i++) {
		forces[i]->draw();
	}
}

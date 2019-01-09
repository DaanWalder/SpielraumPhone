#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();

	ofVideoPlayer startScreen;
	ofVideoPlayer callingScreen;
	ofVideoPlayer onPhoneScreen;

	ofArduino arduino;
	void setupArduino(const int& version);
};
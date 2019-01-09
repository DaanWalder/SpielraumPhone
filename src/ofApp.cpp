#include "ofApp.h"

#define PIN_LDR 0
#define PIN_SECONDLDR 1

void ofApp::setup() {
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	arduino.connect("COM3", 57600);
	arduino.sendFirmwareVersionRequest();

	ofSetFullscreen(0);

	startScreen.load("startScreen.mp4");
	callingScreen.load("callingScreen.mp4");
	onPhoneScreen.load("onPhoneScreen.mp4");
}

void ofApp::setupArduino(const int& version) {
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
	ofLog() << "Arduino firmware found: " << arduino.getFirmwareName()
		<< " v" << arduino.getMajorFirmwareVersion() << "." << arduino.getMinorFirmwareVersion();
	arduino.sendAnalogPinReporting(0, ARD_ANALOG);
	arduino.sendAnalogPinReporting(1, ARD_ANALOG);
}

void ofApp::update() {
	arduino.update();
	startScreen.update();
	callingScreen.update();
	onPhoneScreen.update();
}

void ofApp::draw() {
	startScreen.draw(0, 0, 1080, 720);
	callingScreen.draw(0, 0, 1080, 720);
	onPhoneScreen.draw(0, 0, 1080, 720);
	if (PIN_LDR <= 10 && PIN_SECONDLDR <= 10)
	{
		startScreen.play();
		callingScreen.stop();
		onPhoneScreen.stop();
	}
	else if (PIN_LDR >= 10 && PIN_SECONDLDR <= 10)
	{
		callingScreen.play();
		startScreen.stop();
		callingScreen.stop();
		onPhoneScreen.stop();
	} 
	else if (PIN_LDR <= 10 && PIN_SECONDLDR >= 10)
	{
		callingScreen.play();
		startScreen.stop();
		callingScreen.stop();
		onPhoneScreen.stop();
	}
	else if (PIN_LDR <= 10 && PIN_SECONDLDR <= 10)
	{
		onPhoneScreen.play();
		callingScreen.stop();
		startScreen.stop();
	}
	std::printf("value1: %.0f\n", PIN_LDR);
	std::printf("value2: %.0f\n", PIN_SECONDLDR);

}
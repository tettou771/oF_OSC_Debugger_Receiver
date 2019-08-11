#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(true);
	ofSetBackgroundColor(40);

	port.addListener(this, &ofApp::portChanged);

	gui.setup();
	gui.add(port.setup("OSC Port", 6000));
}

//--------------------------------------------------------------
void ofApp::update(){
	// osc receive
	while (osc.hasWaitingMessages()) {
		ofxOscMessage message;
		osc.getNextMessage(message);

		string addr = message.getAddress();
		string typestr = message.getTypeString();

		stringstream debugMessage;
		debugMessage << "OSC received: " << addr;
		debugMessage << " " << typestr;
		for (int i = 0; i < typestr.length(); ++i) {
			char c = typestr[i];
			switch (c) {
			case 's': debugMessage << ' ' << message.getArgAsString(i); break;
			case 'i': debugMessage << ' ' << message.getArgAsInt(i); break;
			case 'f': debugMessage << ' ' << message.getArgAsFloat(i); break;
			case 'd': debugMessage << ' ' << message.getArgAsDouble(i); break;
			case 'T': debugMessage << ' ' << "True"; break;
			case 'F': debugMessage << ' ' << "False"; break;
			default: debugMessage << ' ' << "Unknown"; break;
			}
		}

		ofxTextFlow::addText(debugMessage.str());
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
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

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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

void ofApp::portChanged(int & _port) {
	osc.setup(_port);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

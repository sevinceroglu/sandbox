#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Smooth edges
	ofEnableSmoothing();

	m_fCounter = 0;
	ofSetCircleResolution(50);
	ofBackground(255, 255, 255);
	m_bSmooth = false;
	ofSetWindowTitle("graphics example");

	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.

	m_pBall0 = std::make_shared< Ball >();
	m_pBall1 = std::make_shared< Ball >();
	m_pBall2 = std::make_shared< Ball >();

	m_pVecBall.push_back( m_pBall0 );
	m_pVecBall.push_back( m_pBall1 );
	m_pVecBall.push_back( m_pBall2 );
}

//--------------------------------------------------------------
void ofApp::update(){
	m_fCounter = m_fCounter + 0.033f;
	
	for ( const auto& ball : m_pVecBall )
	{
		ball->moveTo( ofRandom(mouseX), ofRandom(mouseY) );
		// set color of balls
		ball->m_oColor.set(ofRandom(255), ofRandom(255), ofRandom(255));
 	}
	//m_pBall.x += (mouseX - m_pBall.x)*0.1;
	//m_pBall.y += (mouseY - m_pBall.y)*0.1;
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackgroundGradient(ofColor::gray, ofColor(30, 10, 30), OF_GRADIENT_CIRCULAR);
	
// 	m_pVecBall.push_back( );
// 	for ( const auto& Ball : m_pVecBall )
// 	{
// 	}
	m_pBall0->draw();
	m_pBall1->draw();
	m_pBall2->draw();

	//--------------------------- circles
	//let's draw a circle:
	ofSetColor(255, 130, 0);
	auto radius = 50 + 10 * sin(m_fCounter);
	ofFill();		// draw "filled shapes"
	//ofCircle(100, 400, radius);

	// now just an outline
	ofNoFill(); 
	ofSetHexColor(0xCCCCCC);
	//ofCircle(100, 400, 80);

	// use the bitMap type
	// note, this can be slow on some graphics cards
	// because it is using glDrawPixels which varies in
	// speed from system to system.  try using ofTrueTypeFont
	// if this bitMap type slows you down.
	
	ofSetHexColor(0x000000);
	//ofDrawBitmapString("circle", 75, 500);


	//--------------------------- rectangles
	ofFill();
	for (auto i = 0; i < 200; i++){
		ofSetColor(static_cast<int>(ofRandom(0, 255)), static_cast<int>(ofRandom(0, 255)), static_cast<int>(ofRandom(0, 255)));
		//ofCircle(ofRandom(100 + 2 * i, 150 + 3 * i), ofRandom(600 + 2 * i, 650 + 2 * i), radius);
		//ofRect(ofRandom(250, 350), ofRandom(350, 450), ofRandom(10, 20), ofRandom(10, 20));
	}
	ofSetHexColor(0x000000);
	//ofDrawBitmapString("rectangles", 275, 500);

	//---------------------------  lines
	// a bunch of red lines, make them smooth if the flag is set

	ofSetHexColor(0xFF0000);
	for (int i = 0; i < 20; i++){
		//ofSetColor((int)ofRandom(0, 255), (int)ofRandom(0, 255), (int)ofRandom(0, 255));
		ofLine(600, rand() % 800, 800, rand() % 600);
		ofLine(400, rand() % 800, 800, rand() % 400);
		ofLine(200, rand() % 800, 800, rand() % 200);
	}

	ofSetHexColor(0x000000);
	/*
	//---------------------------  transparency
	ofSetHexColor(0x00FF33);
	ofRect(400, 350, 100, 100);
	// alpha is usually turned off - for speed puposes.  let's turn it on!
	ofEnableAlphaBlending();
	ofSetColor(255, 0, 0, 127);   // red, 50% transparent
	ofRect(450, 430, 100, 33);
	ofSetColor(255, 0, 0, (int)(m_fCounter * 10.0f) % 255);   // red, variable transparent
	ofRect(450, 370, 100, 33);
	ofDisableAlphaBlending();

	ofSetHexColor(0x000000);
	ofDrawBitmapString("transparency", 410, 500);

	//---------------------------  lines
	// a bunch of red lines, make them smooth if the flag is set

	ofSetHexColor(0xFF0000);
	for (int i = 0; i < 20; i++){
		ofLine(600, 300 + (i * 5), 800, 250 + (i * 10));
	}

	ofSetHexColor(0x000000);
	ofDrawBitmapString("lines\npress 's' to toggle smoothness", 600, 500);
	*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's'){
		m_bSmooth = !m_bSmooth;
		if (m_bSmooth){
			ofEnableAntiAliasing();
		}
		else{
			ofDisableAntiAliasing();
		}
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

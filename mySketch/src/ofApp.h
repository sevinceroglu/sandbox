#pragma once

#include "ofMain.h"
#include "ball.h"


class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	float 	m_fCounter;
	bool	m_bSmooth;

	std::shared_ptr< Ball >	m_pBall0,
		m_pBall1,
		m_pBall2;

	std::vector < std::shared_ptr < Ball > >	m_pVecBall;
};

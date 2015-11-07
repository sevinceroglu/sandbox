#ifndef ball_h
#define ball_h

#include "ofMain.h"

class Ball {
public:
	// Constructor
	Ball();
	~Ball();

	// Methods
	void moveTo(int _xDestiny, int _yDestiny);
	void draw();
	
	// Properties
	ofColor m_oColor;

private:

	ofVec2f  m_vec2fPosition;
};
#endif
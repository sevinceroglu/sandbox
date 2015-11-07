#include "ball.h"

Ball::Ball(){
	// Set the initial color
	m_oColor.set( ofRandom( 255 ), ofRandom( 255 ), ofRandom( 255 ) );

	// Initial x position of the Ball
	m_vec2fPosition.x = ofRandom( ofGetWindowWidth() );

	// Initial y position of the Ball
	m_vec2fPosition.y = ofRandom( ofGetWindowHeight() );
}

Ball::~Ball()
{
}

void Ball::moveTo(int _xDestiny, int _yDestiny){
	m_vec2fPosition.x += ( _xDestiny - m_vec2fPosition.x ) * 0.1;
	m_vec2fPosition.y += ( _yDestiny - m_vec2fPosition.y ) * 0.1;
}

void Ball::draw(){
	ofSetColor( m_oColor );
	ofFill();
	ofCircle(m_vec2fPosition.x, m_vec2fPosition.y, 30);
}



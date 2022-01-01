/*
	file: point.cpp
	by: Jake Hanson
	org: COP 2001, 10409
	desc: implementaion of a point class object
*/
#include "point.h"

// constructors
//---------------------------------------------------------------------------------------
/**
 default constructor - initialize empty point

*/
Point::Point() {
	xpos = 0;
	ypos = 0;
}
/**
 properties constructor - initialize to parameter values
*/
Point::Point(float x, float y) {
	xpos = x;
	ypos = y;
}

// accessors
//---------------------------------------------------------------------------------------
// getters
float Point::getXCoordinate() { return xpos; }
float Point::getYCoordinate() { return ypos; }

// setters
void Point::setXCoordinate(float value) { xpos = value; }
void Point::setYCoordinate(float value) { ypos = value; }

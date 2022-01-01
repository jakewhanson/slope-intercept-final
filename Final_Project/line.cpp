/*
	file: line.cpp
	by: Jake Hanson
	org: COP 2001, 10409
	desc: implementaion of a line class object
*/
#define _USE_MATH_DEFINES	// enable M_PI
#include <math.h>			// sqrt, pow, M_PI

#include "line.h"

// constructors
//---------------------------------------------------------------------------------------
/**
 default constructor - initialize empty line

*/
Line::Line() {
	coordsOne = Point();
	coordsTwo = Point();
	slopeP = 0;
}
/**
 properties constructor - initialize to parameter values
*/
Line::Line(Point one, Point two, float slope) {
	coordsOne = one;
	coordsTwo = two;
	this->slopeP = slope;
}

// accessors
//---------------------------------------------------------------------------------------
// getters
Point Line::getPointOneCoords() { return coordsOne; }
Point Line::getPointTwoCoords() { return coordsTwo; }
float Line::getSlope() { return slopeP; }

// setters
void Line::setPointOneCoords(Point value) {
	coordsOne = value;
}
void Line::setPointTwoCoords(Point value) {
	coordsTwo = value;
}
void Line::setSlope(float value) { slopeP = value; }

// member methods
//---------------------------------------------------------------------------------------
/**
 Calculates difference in X between the two points
*/
float Line::calcDiffX() {
	return (coordsTwo.getXCoordinate() - coordsOne.getXCoordinate());
}

/**
 Calculates difference in Y between the two points
*/
float Line::calcDiffY() {
	return (coordsTwo.getYCoordinate() - coordsOne.getYCoordinate());
}

/**
 Calculates slope
 Returns the slope of the line as a float
 Formula = (y_2 - y_1)/(x_2 - x_1)
*/
float Line::calcSlope() {
	return (calcDiffY() / calcDiffX());
}

/**
 Calculates y-intercept
 Takes a Point and slope parameter and returns the y-intercept as a float
 Formula = (y - (slope * x))
*/
float Line::calcY_Int() {
	return (coordsOne.getYCoordinate() - (getSlope() * coordsOne.getXCoordinate()));
}

/**
 Calculates length
 Returns the distance between between two points as a float
 Formula = d(P,Q) = sqrt((x_2 - x_1)^2 + (y_2 - y_1)^2)
*/
float Line::calcLength() {
	return sqrt(pow(calcDiffX(), 2.0) + pow(calcDiffY(), 2.0));
}

/**
 Calculates angle
 Returns the line's angle from the top of the Y axis, or zero degrees, as a float.
 Formula = (90 - inverseTan(((y_2 - y_1)/(x_2 - x_1))*(180/pi)) % 360
*/
float Line::calcAngle() {
	float radians = atan2(coordsTwo.getYCoordinate() - coordsOne.getYCoordinate(), coordsTwo.getXCoordinate() - coordsOne.getXCoordinate());
	float angle = radians * 180.0 / M_PI;							// relative to X-axis
	float degrees = 90.0 - angle;									// rotate angle to left 90 degrees
	float cardinal = (degrees > 0.0 ? degrees : degrees + 360.0);	// fix negative cardinal degrees
	return cardinal;
}

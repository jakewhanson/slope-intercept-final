/*
	file: line.h
	by: Jake Hanson
	org: COP 2001, 10409
	desc: declaration of a line class object
*/
#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line {
public:
	// constructors
	//---------------------------------------------------------------------------------------
	Line();
	Line(Point one, Point two, float slope);

	// accessors
	//---------------------------------------------------------------------------------------
	// getters
	Point getPointOneCoords();
	Point getPointTwoCoords();
	float getSlope();

	// setters
	void setPointOneCoords(Point value);
	void setPointTwoCoords(Point value);
	void setSlope(float value);

	// member methods
	//---------------------------------------------------------------------------------------
	float calcDiffX();
	float calcDiffY();
	float calcSlope();
	float calcY_Int();
	float calcLength();
	float calcAngle();

private:
	Point coordsOne;
	Point coordsTwo;
	float slopeP;

};

#endif // LINE_H
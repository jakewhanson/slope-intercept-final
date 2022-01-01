/*
	file: point.h
	by: Jake Hanson
	org: COP 2001, 10409
	desc: declaration of a point class object
*/
#ifndef POINT_H
#define POINT_H

class Point {
public:
	// constructors
	//---------------------------------------------------------------------------------------
	Point();
	Point(float x, float y);

	// accessors
	//---------------------------------------------------------------------------------------
	// getters
	float getXCoordinate();
	float getYCoordinate();

	// setters
	void setXCoordinate(float value);
	void setYCoordinate(float value);

private:
	float xpos;
	float ypos;
};

#endif // POINT_H
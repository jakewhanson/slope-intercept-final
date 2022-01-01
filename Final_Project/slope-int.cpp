/*
	file: slope-int.cpp
	by: Jake Hanson
	org: COP 2001, 10409
	desc: Given input from the user, finds the slope-intercept and shows a graph to the user using OpenGL.
*/
#include <iostream>			// console library for debugging
#include <iomanip>			// console library for setprecision

#include "fgcugl.h"			// fgcu OpenGL library
#include "line.h"			// line header file

// global constants
// const int GRAPH;
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 400;
const std::string WINDOW_TITLE = "Linear Graph";
int mode = -1;

// global data structures
enum Mode {
	TWO_POINT,
	POINT_SLOPE,
	EXIT
};

// function prototypes
int getProblem();
Point getPoint();
void get2Point(Line& line);
void getPointSlope(Line& line);

// displays
void displayLine(Line& line);
void display2Pt(Line line);
void displayPointSlope(Line line);
void displaySlopeIntercept(Line line);
void drawLine(Line line);

// begin main
int main()
{
	do {
		mode = getProblem();	// retrieves user input, then uses it to determine what functions to call
		if (mode == TWO_POINT) {
			Line line = Line(line.getPointOneCoords(), line.getPointTwoCoords(), line.calcSlope());		// define line var for two point form
			get2Point(line);
			displayLine(line);
			display2Pt(line);
			drawLine(line);
		}
		else if (mode == POINT_SLOPE) {
			Line line = Line(line.getPointOneCoords(), {0, line.calcY_Int()}, line.getSlope());			// define line var for point slope form
			getPointSlope(line);
			displayLine(line);
			displayPointSlope(line);
			drawLine(line);
		}
		else if (mode == EXIT) {
			std::cout << "Exiting program. Thank you." << std::endl;
		}
	} while (mode != EXIT);

	return 0;
} // end main

// begin functions -------------------------------------------------------------------------------------
int getProblem()
{
	// Displays user menu, prompts for menu choice and returns enum Mode value entered by user (subtracting 1)
	int input = 0;
	std::cout << "Select the form that you would like to convert to slope-intercept form:" << std::endl;
	std::cout << "\t1) Two-point form (you know the two points of the line)" << std::endl;
	std::cout << "\t2) Point-slope form (you know the line's slope and one point)" << std::endl;
	std::cout << "\t3) exit" << std::endl;
	std::cout << "=> ";
	std::cin >> input;
	std::cout << "\n";

	return (input - 1);
}

Point getPoint()
{
	// Prompt user for an X and Y coordinate and returns them as a Point structure
	// create point vars
	float x;
	float y;
	std::cout << "Enter X and Y coordinates seperated by spaces: ";
	std::cin >> x;
	std::cin >> y;
	std::cout << "" << std::endl;
	Point point = Point(x, y);
	return point;
}

void get2Point(Line& line)
{
	// Takes a Line as a parameter and calls getPoint() two times to populate the two point properties of the line
	// create point vars
	Point pointOne;
	std::cout << "Enter the first point: " << "\n" << std::endl;
	pointOne = getPoint();

	Point pointTwo;
	std::cout << "Enter the second point: " << "\n" << std::endl;
	pointTwo = getPoint();

	line.setPointOneCoords(pointOne);
	line.setPointTwoCoords(pointTwo);
	line.setSlope(line.calcSlope());
}

void getPointSlope(Line& line)
{
	// Takes a Line as a parameter and calls getPoint() to populate one of the point properties and a slope value
	Point pointOne;
	std::cout << "Enter a point for the line:" << std::endl;
	pointOne = getPoint();
	
	float slope;
	std::cout << "Enter the slope of the line: ";
	std::cin >> slope;
	
	line.setPointOneCoords(pointOne);
	line.setSlope(slope);
	line.setPointTwoCoords({ 0, line.calcY_Int() });
}

// begin Display Functions --------------------------------------------------------------------------------
void displayLine(Line& line)
{
	// Takes a Line and displays property values on the console
	std::cout << "Line:" << std::endl;
	std::cout << "	 Point-1:  " << "(" << std::fixed << std::setprecision(0) << line.getPointOneCoords().getXCoordinate() << ", " << line.getPointOneCoords().getYCoordinate() << ")" << std::endl;
	std::cout << "	 Point-2:  " << "(" << std::fixed << std::setprecision(0) << line.getPointTwoCoords().getXCoordinate() << ", " << line.getPointTwoCoords().getYCoordinate() << ")" << std::endl;
	std::cout << "	   Slope = " << std::setprecision(2) << line.getSlope() << std::endl;
	std::cout << "	Y-Intcpt = " << std::fixed << std::setprecision(1) << line.calcY_Int() << std::endl;
	std::cout << "	  Length = " << std::fixed << std::setprecision(0) << line.calcLength() << std::endl;
	std::cout << "	   Angle = " << std::fixed << std::setprecision(0) << line.calcAngle() << std::endl;
	std::cout << "\n" << std::endl;
}

void display2Pt(Line line)
{
	// Takes a Line and displays the two-point form of the line on the console
	std::cout << "Two-point form:" << std::endl;
	std::cout << "	    (" << line.getPointTwoCoords().getYCoordinate() << " - " << line.getPointOneCoords().getYCoordinate() << ")" << std::endl;
	std::cout << "	m = ----------------" << std::endl;
	std::cout << "	    (" << line.getPointTwoCoords().getXCoordinate() << " - " << line.getPointOneCoords().getXCoordinate() << ")\n" << std::endl;
	displaySlopeIntercept(line);
}

void displayPointSlope(Line line)
{
	// Takes a Line and displays the point slope form of the line on the console
	std::cout << "Point-slope form:" << std::endl;
	std::cout << "	y - " << std::setprecision(0) << line.getPointOneCoords().getYCoordinate() << " = " << std::setprecision(1) << line.getSlope() << "(x - " << std::setprecision(0) << line.getPointOneCoords().getXCoordinate() << ")\n" << std::endl;
	displaySlopeIntercept(line);
}

void displaySlopeIntercept(Line line)
{
	// Takes a Line and displays the slope-intercept form of the line on the console
	std::cout << "Slope-intercept form:" << std::endl;
	std::cout << "	y = " << std::setprecision(2) << line.getSlope() << "x + " << std::setprecision(1) << line.calcY_Int() << "\n" << std::endl;
}

void drawLine(Line line)
{
	// Takes a Line and graphs the line on an OpenGL window with X and Y axis
	fgcugl::openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	while (fgcugl::windowClosing() == false) {
		// recolor background
		fgcugl::drawQuad(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, fgcugl::Silver);

		// draw main slope line
		fgcugl::drawLine((line.getPointOneCoords().getXCoordinate() * 2 + WINDOW_WIDTH) / 2, (line.getPointOneCoords().getYCoordinate() * 2 + WINDOW_HEIGHT) / 2,
			(line.getPointTwoCoords().getXCoordinate() * 2 + WINDOW_WIDTH) / 2, (line.getPointTwoCoords().getYCoordinate() * 2 + WINDOW_HEIGHT) / 2, 2, fgcugl::Blue);

		// draw x-axis line
		fgcugl::drawLine(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2, 1, fgcugl::Black);
		// draw y-axis line
		fgcugl::drawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, 1, fgcugl::Black);

		fgcugl::windowPaint();
		fgcugl::getEvents();
	}
	fgcugl::cleanup();
}
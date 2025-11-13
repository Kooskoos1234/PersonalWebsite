#ifndef force_H
#define force_H
#include <vector>
#include <utility>
#include <iostream>
#include <cmath>

//Force struct: stores a magnitude and an angle, along with a print function to send them with the appropriate units.
struct Force
{
	double magnitude;
	double angle;

	std::pair<double, double> components;

	//constructor with magnitude and angle initialized.
	Force(double magnitude, double angle);

	//constructor with x and y initialized. use std::make_pair to initialize the xy pair
	Force(std::pair<double, double> components);

	//default constructor. 
	Force();

	//Prints the force's values in a format dependent on boolean value
	//	true:Newtons and Degrees. If the magnitude is 0, prints "0N."
	//	false: x and y. Prints exactly in the format (x, y).
	void print(bool format);
};

//Quadrant enum: stores which quadrant an angle would be on in a standard graph. 
enum Quadrant
{
	QI,
	QII,
	QIII,
	QIV
};

//performs the absolute value operation for floating point types. This is an undefined function for floats by default. 
double floatAbs(double x);

//performs the modulus operation, for floating point types. 
//unfortunately this cannot be an overloaded operator, as operator overloads require the user to use different types. 
double floatMod(double x, double y);

//asks the user how many forces they would like to enter. Then, asks them for the magnitude and angle of each force.
//the forces are stored in my Force struct, and returned as a vector of the class. 
std::vector<Force> retrieveForces();

//Compounds a provided list of forces to get the resultant force. 
Force getResultant(std::vector<Force> forceList);

//gets the vector of the force that would be required to cancel out the passed force.
Force getEquillibrant(Force force);

#endif
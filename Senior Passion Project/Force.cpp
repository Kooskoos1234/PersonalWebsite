#include "Force.h"

constexpr double PI = 3.141592653589793;

Force::Force(double magnitude, double angle)
{
	this->magnitude = magnitude;
	this->angle = angle;
}

Force::Force(std::pair<double, double> components) {
	double x = std::get<0>(components);
	double y = std::get<1>(components);
	this->components = components;
	this->magnitude = sqrt(pow(x, 2) + pow(y, 2));
	double resultantAngle = floatAbs(std::atan(floatAbs(y) / floatAbs(x))) * 180 / PI;
	Quadrant Q = (x >= 0) ? ((y >= 0) ? QI : QIV) : ((y >= 0) ? QII : QIII);

	switch (Q) {
	case Quadrant::QI:
		break;
	case Quadrant::QII:
		resultantAngle = 180 - resultantAngle;
		break;
	case Quadrant::QIII:
		resultantAngle += 180;
		break;
	case Quadrant::QIV:
		resultantAngle = 360 - resultantAngle;
		break;
	}

	resultantAngle = (floatAbs(x) <= 1e-8) && (floatAbs(y) <= 1e-8) ? 0 : resultantAngle;
	resultantAngle = (floatMod(resultantAngle, 360.0) <= 360.1 && floatMod(resultantAngle, 360.0) >= 359.9) ? 0 : floatMod(resultantAngle, 360.0);
	this->angle = resultantAngle;
}

Force::Force(){
	this->angle = 0;
	this->magnitude = 0;
}

void Force::print(bool format)
{
	if (format == true)
	{
		if (this->magnitude == 0)
		{
			std::cout << "0N.\n";
		}
		else
		{
			std::cout << this->magnitude << "N at " << this->angle << "°.\n";
		}
	}
	else
	{
		std::cout << '(' << std::get<0>(this->components) << ", " << std::get<1>(this->components) << ')';
	}
}

double floatAbs(double x)
{
	return (x <= 0 ? x * -1 : x);
}

double floatMod(double x, double y)
{
	while (x >= y) {
		x -= y;
	}
	while (x <= 0) {
		x += y;
	}
	return x;
}

std::vector<Force> retrieveForces()
{
	int forceCount = 0;

	std::cout << "How many forces would you like to enter? ";
	std::cin >> forceCount;

	std::vector<Force> forceList;
	for (int i = 0; i < forceCount; i++) {
		std::cout << "Enter the magnitude of a force. Then, enter the angle at which that force is applied. \n";
		double magnitude;
		double angle;
		std::cin >> magnitude >> angle;
		Force force;
		force.magnitude = magnitude;
		force.angle = angle;
		forceList.push_back(force);
	}
	return forceList;
}

Force getResultant(std::vector<Force> forceList)
{
	double xComp{ 0 };
	double yComp{ 0 };

	for (int i = 0; i < forceList.size(); i++) {
		xComp += forceList[i].magnitude * std::cos(forceList[i].angle * PI / 180);
		yComp += forceList[i].magnitude * std::sin(forceList[i].angle * PI / 180);
	}

	double resultantMagnitude = sqrt(pow(xComp, 2) + pow(yComp, 2));
	double resultantAngle = floatAbs(std::atan(floatAbs(yComp) / floatAbs(xComp))) * 180 / PI;
	Quadrant Q = (xComp >= 0) ? ((yComp >= 0) ? QI : QIV) : ((yComp >= 0) ? QII : QIII);

	switch (Q) {
	case Quadrant::QI:
		break;
	case Quadrant::QII:
		resultantAngle = 180 - resultantAngle;
		break;
	case Quadrant::QIII:
		resultantAngle += 180;
		break;
	case Quadrant::QIV:
		resultantAngle = 360 - resultantAngle;
		break;
	}

	resultantMagnitude = (floatAbs(xComp) <= 1e-8) && (floatAbs(yComp) <= 1e-8) ? 0 : resultantMagnitude;
	resultantAngle = (floatAbs(xComp) <= 1e-8) && (floatAbs(yComp) <= 1e-8) ? 0 : resultantAngle;
	resultantAngle = (floatMod(resultantAngle, 360.0) <= 360.1 && floatMod(resultantAngle, 360.0) >= 359.9) ? 0 : floatMod(resultantAngle, 360.0);
	Force resultant(resultantMagnitude, resultantAngle);
	return resultant;
}

Force getEquillibrant(Force force)
{
	Force equillibrant(force.magnitude, (force.angle < 180 ? force.angle + 180 : force.angle - 180));
	return equillibrant;
}
#include "Vector.h"

#include <math.h>

Vector::Vector(): x(0), y(0) {};
Vector::Vector(float x, float y): x(x), y(y) {}

int Vector::GetQuadrant() {
	if(x >= 0 && y >= 0) return 1;
	if(x < 0 && y >= 0) return 2;
	if(x < 0 && y < 0) return 3;
	return 4;
}

float Vector::GetAngleRad() {
	return atan2(y, x);
}

float Vector::GetMagnitude(bool account_for_quadrant) {
	return sqrt(pow(x, 2) + pow(y, 2)) * ((account_for_quadrant && (GetQuadrant() > 2)) ? -1 : 1);
}

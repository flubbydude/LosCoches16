/*
 * Vector.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Noah-Huppert
 */

#ifndef SRC_MODELS_VECTOR_H_
#define SRC_MODELS_VECTOR_H_

struct Vector {
	float x;
	float y;

	Vector();
	Vector(float x, float y);

	int GetQuadrant();
	float GetAngleRad();
	float GetMagnitude(bool account_for_quadrant);
};

#endif /* SRC_MODELS_VECTOR_H_ */

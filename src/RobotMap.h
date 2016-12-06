#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

namespace RobotMap {
	const int OPERATOR_CONTROLLER_PORT = 0;

	const int LEFT_PRIMARY_MOTOR = 2;// CAN - Talon
	const int LEFT_SECONDARY_MOTOR = 3;// CAN - Jaguar

	const int RIGHT_PRIMARY_MOTOR = 1;// CAN - Talon
	const int RIGHT_SECONDARY_MOTOR = 4;// CAN - Jaguar

	const int RIGHT_SHOOTER_MOTOR = 6;// PWM - Talon
	const int LEFT_SHOOTER_MOTOR = 7;// PWM - Talon

	const int INTAKE_MOTOR = 8;// PWM - Talon
}

#endif
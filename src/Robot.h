#ifndef ROBOT_H
#define ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"

#include "Subsystems/DriveTrain.h"

#include "OI.h"

class Robot: public IterativeRobot {
public:
	static std::shared_ptr<DriveTrain> drive_train;

	static std::unique_ptr<OI> oi;

	std::unique_ptr<Gyro> gyro;

private:
	std::unique_ptr<Command> autonomousCommand;
	double last_inverted_time;

	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif

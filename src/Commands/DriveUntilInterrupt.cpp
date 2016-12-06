#include "DriveUntilInterrupt.h"
#include "../Robot.h"

DriveUntilInterrupt::DriveUntilInterrupt(float drive_speed): drive_speed(drive_speed){
	Requires(Robot::drive_train.get());
}

// Called just before this Command runs the first time
void DriveUntilInterrupt::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveUntilInterrupt::Execute() {
	Robot::drive_train->Drive(drive_speed, drive_speed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilInterrupt::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveUntilInterrupt::End() {
	Robot::drive_train->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilInterrupt::Interrupted() {
	End();
}

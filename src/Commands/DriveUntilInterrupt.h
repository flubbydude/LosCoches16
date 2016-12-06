#ifndef DriveUntilInterrupt_H
#define DriveUntilInterrupt_H

#include "Commands/Command.h"
#include "WPILib.h"

class DriveUntilInterrupt: public Command {
public:
	DriveUntilInterrupt(float drive_speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float drive_speed;
};

#endif

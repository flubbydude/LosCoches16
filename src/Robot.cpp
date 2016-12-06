#include "Robot.h"

#include "RobotMap.h"

std::shared_ptr<DriveTrain> Robot::drive_train;

std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	drive_train.reset(new DriveTrain());

	oi.reset(new OI());

	last_inverted_time = GetTime();

	gyro = std::unique_ptr<Gyro>(new AnalogGyro(1));


	CameraServer::GetInstance()->SetQuality(0.25);
	//the camera name (ex "cam0") can be found through the roborio web interface
	CameraServer::GetInstance()->StartAutomaticCapture("cam0");
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand != NULL) autonomousCommand->Cancel();

	drive_train->Reset();
	oi->xbox_controller->Calibrate();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	SmartDashboard::PutNumber("Gyro", gyro->GetAngle());

	if(oi->xbox_controller->GetButton(XBoxController::BUTTON_START)) {
		oi->xbox_controller->Calibrate();
	}

	SmartDashboard::PutNumber("LAST", GetTime() - last_inverted_time);
	drive_train->PrintInvertedStatus();
	if(GetTime() - last_inverted_time >= 1000 && oi->xbox_controller->GetButton(XBoxController::BUTTON_A)) {
		drive_train->InvertDirection();
	}
}

void Robot::TestPeriodic() {
	LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)


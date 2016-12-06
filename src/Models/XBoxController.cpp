/*
 * XBoxController.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: Noah-Huppert
 */

#include <map>
#include "XBoxController.h"

XBoxController::XBoxController(int port) {
	wpilib_joystick = std::unique_ptr<Joystick>(new Joystick(port));

	left_stick_offset = Vector(0.5, 0.5);
	right_stick_offset = Vector(0.5, 0.5);
}

Vector XBoxController::GetStick(int xId, int yId, Vector offset) {
	float xRaw = wpilib_joystick->GetRawAxis(xId);
	float yRaw = wpilib_joystick->GetRawAxis(yId);

	return Vector(xRaw - offset.x, yRaw - offset.y);
}

float XBoxController::GetTrigger(int id) {
	float raw = wpilib_joystick->GetRawAxis(id);
	return (raw - 0.5) * 2;// Trigger is an axis that starts(Unpressed) with the value 0.5
}

Vector XBoxController::GetLeftStick() {
	return GetStick(AXIS_LEFT_STICK_X_ID, AXIS_LEFT_STICK_Y_ID, left_stick_offset);
}

Vector XBoxController::GetRightStick() {
	return GetStick(AXIS_RIGHT_STICK_X_ID, AXIS_RIGHT_STICK_Y_ID, right_stick_offset);
}

bool XBoxController::GetButton(int id) {
	return wpilib_joystick->GetRawButton(id);
}

bool XBoxController::GetDPad(int angle) {
	return angle == wpilib_joystick->GetPOV();
}

float XBoxController::GetLeftTrigger() {
	return GetTrigger(AXIS_LEFT_TRIGGER_ID);
}

float XBoxController::GetRightTrigger() {
	return GetTrigger(AXIS_RIGHT_TRIGGER_ID);
}

bool XBoxController::GetLeftTriggerAsButton() {
	return GetLeftTrigger() >= LEFT_TRIGGER_BUTTON_THRESHOLD;
}

bool XBoxController::GetRightTriggerAsButton() {
	return GetRightTrigger()>= RIGHT_TRIGGER_BUTTON_THRESHOLD;
}

std::shared_ptr<JoystickButton> XBoxController::GetJoystickButton(int id) {
	if(joystick_button_map.count(id) == 0) {
		joystick_button_map[id] = std::shared_ptr<JoystickButton>(new JoystickButton(wpilib_joystick.get(), id));
	}

	return joystick_button_map[id];
}

std::shared_ptr<XboxControllerTriggerButton> XBoxController::GetTriggerJoystickButton(int id, float threshold) {
	if(trigger_joystick_button_map.count(id) == 0) {
		trigger_joystick_button_map[id] = std::shared_ptr<XboxControllerTriggerButton>(
				new XboxControllerTriggerButton(this, id, threshold)
		);
	}

	return trigger_joystick_button_map[id];
}

XboxControllerTriggerButton::XboxControllerTriggerButton(XBoxController *controller, int trigger_id, float pressed_threshold):
		controller(controller),
		trigger_id(trigger_id),
		pressed_threshold(pressed_threshold) {

}

bool XboxControllerTriggerButton::Get() {
	return controller->GetTrigger(trigger_id) >= pressed_threshold;
}

void XBoxController::Calibrate() {
	left_stick_offset = Vector(wpilib_joystick->GetRawAxis(AXIS_LEFT_STICK_X_ID),
								wpilib_joystick->GetRawAxis(AXIS_LEFT_STICK_Y_ID));


	right_stick_offset = Vector(wpilib_joystick->GetRawAxis(AXIS_RIGHT_STICK_X_ID),
								wpilib_joystick->GetRawAxis(AXIS_RIGHT_STICK_Y_ID));
}

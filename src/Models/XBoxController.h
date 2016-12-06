/*
 * XBoxController.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Noah-Huppert
 */

#ifndef SRC_MODELS_XBOXCONTROLLER_H_
#define SRC_MODELS_XBOXCONTROLLER_H_

#include "WPILib.h"

#include "Vector.h"

class XboxControllerTriggerButton;

class XBoxController {
public:
	// Axis Ids
	const static int AXIS_LEFT_STICK_X_ID = 0;
	const static int AXIS_LEFT_STICK_Y_ID = 1;

	const static int AXIS_RIGHT_STICK_X_ID = 4;
	const static int AXIS_RIGHT_STICK_Y_ID = 5;

	const static int AXIS_LEFT_TRIGGER_ID = 2;
	const static int AXIS_RIGHT_TRIGGER_ID = 3;

	// Button Ids
	const static int BUTTON_LEFT_STICK_CLICK = 9;
	const static int BUTTON_RIGHT_STICK_CLICK = 10;

	const static int BUTTON_LEFT_BUMPER = 5;
	const static int BUTTON_RIGHT_BUMPER = 6;

	const static int BUTTON_A = 1;
	const static int BUTTON_B = 2;
	const static int BUTTON_X = 3;
	const static int BUTTON_Y = 4;

	const static int BUTTON_BACK = 7;
	const static int BUTTON_START = 8;

	// DPad
	const static int DPAD_UP = 0;
	const static int DPAD_UP_RIGHT = 45;
	const static int DPAD_RIGHT = 90;
	const static int DPAD_DOWN_RIGHT = 135;
	const static int DPAD_DOWN = 180;
	const static int DPAD_DOWN_LEFT = 225;
	const static int DPAD_LEFT = 270;
	const static int DPAD_UP_LEFT = 315;

	// Other
	constexpr static float LEFT_TRIGGER_BUTTON_THRESHOLD = 0.8;
	constexpr static float RIGHT_TRIGGER_BUTTON_THRESHOLD = 0.8;

	XBoxController(int port);

	// Getters
	Vector GetLeftStick();
	Vector GetRightStick();

	Vector GetStick(int xId, int yId, Vector offset);
	float GetTrigger(int id);

	bool GetButton(int id);

	bool GetDPad(int angle);

	float GetLeftTrigger();
	float GetRightTrigger();

	bool GetLeftTriggerAsButton();
	bool GetRightTriggerAsButton();

	std::shared_ptr<JoystickButton> GetJoystickButton(int id);
	std::shared_ptr<XboxControllerTriggerButton> GetTriggerJoystickButton(int id, float threshold);

	void Calibrate();

private:
	std::map<int, std::shared_ptr<JoystickButton>> joystick_button_map;
	std::map<int, std::shared_ptr<XboxControllerTriggerButton>> trigger_joystick_button_map;

	std::unique_ptr<Joystick> wpilib_joystick;

	Vector left_stick_offset;
	Vector right_stick_offset;
};

class XboxControllerTriggerButton: public Button {
private:
	XBoxController *controller;

	int trigger_id;
	float pressed_threshold;

public:
	XboxControllerTriggerButton(XBoxController *controller, int trigger_id, float pressed_threshold);

	bool Get();
};

#endif /* SRC_MODELS_XBOXCONTROLLER_H_ */

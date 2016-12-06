#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "Models/XBoxController.h"

class OI {
public:
	std::shared_ptr<XBoxController> xbox_controller;

	OI();
};

#endif

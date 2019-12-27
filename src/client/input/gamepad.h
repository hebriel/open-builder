
#pragma once

#include <vector>
#include "button.h"

class Gamepad final
{
public:
	explicit Gamepad(Joystick joystick);

	/**
	* @brief Vector of buttons
	*
	* @return Constant reference to a vector containing all buttons
	*/
	[[nodiscard]] const std::vector<Button>& getButtons() const;

	/**
	* @brief Associated joystick
	*
	* @return Constant reference to the Joystick associated with this gamepad
	*/
	[[nodiscard]] const Joystick& getJoystick() const;

	void update();

private:
	Joystick m_joystick;
	std::vector<Button> m_buttons;

};



#pragma once

#include <SFML/Window/Joystick.hpp>
#include "input.h"
#include "joystick.h"

/**
 * @brief Represents a physical button on a gamepad
 *
 * @details A button only has 2 states, pushed or idle. When pushed, getValue() will return 1.0f. 0.0f otherwise.
 */
class Button final : public Input
{
public:
	explicit Button(Joystick& joystick, unsigned button);

	/**
	* @brief Updates the internal value of the input
	*/
	void update() override;

private:
	Joystick& m_joystick;
	unsigned m_button {};
};


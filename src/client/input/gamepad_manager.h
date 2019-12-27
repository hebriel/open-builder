
#pragma once

#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Event.hpp>
#include <array>
#include <list>
#include "joystick.h"
#include "gamepad.h"

class Button;

class GamepadManager final
{
public:
	GamepadManager();

	/**
	 * @brief Updates the gamepad list
	 */
	void update(const sf::Event& e);

private:
	std::list<Gamepad> m_gamepads;

};


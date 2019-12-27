#include <iostream>
#include "gamepad_manager.h"

GamepadManager::GamepadManager()
{
	for (unsigned i {0}; i < sf::Joystick::Count; ++i) {
		if (sf::Joystick::isConnected(i)) {
			m_gamepads.emplace_back(Gamepad(Joystick(i)));
		}
	}
}

void GamepadManager::update(const sf::Event& e)
{
	if (e.type == sf::Event::JoystickButtonPressed)
	{
		exit(-1);
	}
	if (e.type == sf::Event::JoystickDisconnected) {

		// Search if the requested gamepad is in the list, and remove it
		for (auto itr = m_gamepads.begin(); itr != m_gamepads.end(); ) {
			//todo: use std::remove_if
			if (itr->getJoystick().getId() == e.joystickConnect.joystickId)
				itr = m_gamepads.erase(itr);
			else
				++itr;
		}
	}
	if (e.type == sf::Event::JoystickConnected) {
		bool gamepadFound = false;
		for (auto& gamepad : m_gamepads) {
			if (gamepad.getJoystick().getId() == e.joystickConnect.joystickId) {
				gamepadFound = true;
				break;
			}
		}
		// Only add it to the list if the gamepad is not already in it (safety check)
		if (!gamepadFound) {
			m_gamepads.emplace_back(Gamepad(Joystick(e.joystickConnect.joystickId)));
		}
	}
}

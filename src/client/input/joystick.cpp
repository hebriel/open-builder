#include <SFML/Window/Joystick.hpp>
#include "joystick.h"

unsigned Joystick::getId() const
{
	return m_id;
}

Joystick::Joystick(unsigned id)
{
	m_id = id;
}

unsigned Joystick::getButtonCount() const
{
	return sf::Joystick::getButtonCount(m_id);
}

float Joystick::getAxisPosition(sf::Joystick::Axis axis) const
{
	return sf::Joystick::getAxisPosition(m_id, axis);
}

sf::Joystick::Identification Joystick::getIdentification() const
{
	return sf::Joystick::getIdentification(m_id);
}

bool Joystick::hasAxis(sf::Joystick::Axis axis) const
{
	return sf::Joystick::hasAxis(m_id, axis);
}

bool Joystick::isConnected() const
{
	return sf::Joystick::isConnected(m_id);
}

bool Joystick::isButtonPressed(unsigned button) const
{
	return sf::Joystick::isButtonPressed(m_id, button);
}

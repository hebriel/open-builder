#include "gamepad.h"

const std::vector<Button>& Gamepad::getButtons() const
{
	return m_buttons;
}

Gamepad::Gamepad(Joystick joystick)
	: m_joystick(joystick)
{
	for (unsigned i {0}; i < joystick.getButtonCount(); ++i) {
		m_buttons.emplace_back(Button(m_joystick, i));
	}
}

void Gamepad::update()
{

}

const Joystick &Gamepad::getJoystick() const
{
	return m_joystick;
}

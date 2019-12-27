#include "button.h"

Button::Button(Joystick& joystick, unsigned button)
	: m_joystick(joystick), m_button(button)
{
	p_name = "[" + joystick.getIdentification().name + "] Button " + std::to_string(button);
}

void Button::update()
{
	Input::update();
	p_value = static_cast<float>(m_joystick.isButtonPressed(m_button));
}


#pragma once

/**
 * @brief Abstraction for a SFML Joystick
 */
class Joystick final
{
public:
	Joystick() = default;

	explicit Joystick(unsigned id);

	[[nodiscard]] unsigned getId() const;

	[[nodiscard]] unsigned getButtonCount() const;

	[[nodiscard]] float getAxisPosition(sf::Joystick::Axis axis) const;

	[[nodiscard]] sf::Joystick::Identification getIdentification() const;

	[[nodiscard]] bool hasAxis(sf::Joystick::Axis axis) const;

	[[nodiscard]] bool isConnected() const;

	[[nodiscard]] bool isButtonPressed(unsigned button) const;

private:

	unsigned m_id {255};
};


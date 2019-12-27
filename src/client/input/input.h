
#pragma once

#include <string>

/**
 * @brief Represents an input. Useful as any type of input can be mapped to any other type of input
 */
class Input
{
public:

	/**
	* @brief Relative value of the axis
	*
	* @return The relative value of the Input, in range -1.0f .. 1.0f
	*/
	[[nodiscard]] float getValue() const;

	/**
	* @brief Name of the Input created by the Gamepad Manager
	*
	* @return Const reference to the name of the Input
	*/
	[[nodiscard]] const std::string& getName() const;

	/**
    * @brief Updates the internal value of the input
	*/
	virtual void update();

	virtual ~Input() = default;

protected:

	float p_value {0.0f};
	std::string p_name;

};

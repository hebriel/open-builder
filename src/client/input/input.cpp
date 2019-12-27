#include "input.h"

float Input::getValue() const
{
	return p_value / 100.f;
}

const std::string& Input::getName() const
{
	return p_name;
}

void Input::update()
{

}

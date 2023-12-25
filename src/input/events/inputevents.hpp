#pragma once
#include <unordered_map>
#include <string>

#include <rsl/math>

#include "core/events/event.hpp"
#include "input/map/inputmap.hpp"

namespace rythe::core::events
{
	using namespace input;

	struct axis_data
	{
		inputmap::method positive, negative;
		float max, min;
	};

	template<inputmap::method Key>
	struct key_input final : public event<key_input<Key>>
	{
	private:
		inputmap::method m_key = Key;
		bool m_lastValue;
		bool m_value;
	public:
		key_input(bool _value, bool _lastValue) : m_value(_value), m_lastValue(_lastValue) {}

		bool isPressed() { return m_value; }
		bool wasPressed() { return (m_value == false && m_lastValue == true); }
	};

	template<axis_data... Inputs >
	struct axis_input final : public event<axis_input<Inputs...>>
	{
	public:
		//std::vector<axis_data> m_axes = { Inputs... };
		std::unordered_map<std::string, float> m_values;
		float getValue(const std::string& axisName) { return m_values[axisName]; }
	};

	struct mouse_input final : public event<mouse_input>
	{
		math::vec2 position;
		math::vec2 lastPosition;
		math::vec2 positionDelta;
		mouse_input(math::vec2 pos, math::vec2 lastPos, math::vec2 posDelta) : position(pos), lastPosition(lastPos), positionDelta(posDelta) {}
	};
}
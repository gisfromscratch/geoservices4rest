/*
 * JsonNumberValue.cpp
 *
 *  Created on: Aug 19, 2012
 *      Author: developer
 */

#include "JsonNumberValue.h"
#include <sstream>

namespace edu
{
namespace json
{

JsonNumberValue::JsonNumberValue(const JsonNode &node)
{
	_value = json_as_float(node);
}

JsonNumberValue::~JsonNumberValue()
{
}

json_number JsonNumberValue::value() const
{
	return _value;
}

string JsonNumberValue::toString()
{
	stringstream stream;
	stream << _value;
	return stream.str();
}

} /* namespace json */
} /* namespace edu */

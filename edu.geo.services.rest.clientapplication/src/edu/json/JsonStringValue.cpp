/*
 * JsonStringValue.cpp
 *
 *  Created on: Aug 19, 2012
 *      Author: developer
 */

#include "JsonStringValue.h"

namespace edu
{
namespace json
{

JsonStringValue::JsonStringValue(const JsonNode &node)
{
	_value = json_as_string(node);
}

JsonStringValue::~JsonStringValue()
{
	json_free(_value);
}

string JsonStringValue::toString()
{
	return _value;
}

} /* namespace json */
} /* namespace edu */

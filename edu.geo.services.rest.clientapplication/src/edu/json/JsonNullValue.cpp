/*
 * JsonNullValue.cpp
 *
 *  Created on: Aug 19, 2012
 *      Author: developer
 */

#include "JsonNullValue.h"

namespace edu
{
namespace json
{

JsonNullValue::JsonNullValue()
{
}

JsonNullValue::~JsonNullValue()
{
}

string JsonNullValue::toString()
{
	return "<Null>";
}

} /* namespace json */
} /* namespace edu */

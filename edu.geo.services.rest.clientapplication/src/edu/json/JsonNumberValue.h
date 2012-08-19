/*
 * JsonNumberValue.h
 *
 *  Created on: Aug 19, 2012
 *      Author: developer
 */

#ifndef JSONNUMBERVALUE_H_
#define JSONNUMBERVALUE_H_

#include <string>

#include "Json.h"
#include "JsonNode.h"

using namespace std;

namespace edu
{
namespace json
{

class JsonNumberValue : public JsonValue
{
public:
	JsonNumberValue(const JsonNode &node);
	~JsonNumberValue();

	json_number value() const;

	string toString();

private:
	json_number _value;
};

} /* namespace json */
} /* namespace edu */
#endif /* JSONNUMBERVALUE_H_ */

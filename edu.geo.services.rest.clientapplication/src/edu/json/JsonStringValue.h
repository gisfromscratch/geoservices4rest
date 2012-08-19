/*
 * JsonStringValue.h
 *
 *  Created on: Aug 19, 2012
 *      Author: developer
 */

#ifndef JSONSTRINGVALUE_H_
#define JSONSTRINGVALUE_H_

#include <string>

#include "Json.h"
#include "JsonNode.h"
#include "JsonValue.h"

using namespace std;

namespace edu
{
namespace json
{

class JsonStringValue : public JsonValue
{
public:
	JsonStringValue(const JsonNode &node);
	~JsonStringValue();

	string toString();

private:
	json_char *_value;
};

} /* namespace json */
} /* namespace edu */
#endif /* JSONSTRINGVALUE_H_ */

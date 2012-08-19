/*
 * JsonNullValue.h
 *
 *  Created on: Aug 19, 2012
 *      Author: developer
 */

#ifndef JSONNULLVALUE_H_
#define JSONNULLVALUE_H_

#include <string>

#include "JsonValue.h"

using namespace std;

namespace edu
{
namespace json
{

class JsonNullValue : public JsonValue
{
public:
	JsonNullValue();
	~JsonNullValue();

	string toString();
};

} /* namespace json */
} /* namespace edu */
#endif /* JSONNULLVALUE_H_ */

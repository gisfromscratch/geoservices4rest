/*
 * JsonValue.h
 *
 *  Created on: Aug 19, 2012
 *      Author: developer
 */

#ifndef JSONVALUE_H_
#define JSONVALUE_H_

#include <string>

#include "Json.h"

using namespace std;

namespace edu
{
namespace json
{

class JsonValue
{
public:
	JsonValue();
	virtual ~JsonValue();

	virtual string toString() = 0;
};

} /* namespace json */
} /* namespace edu */
#endif /* JSONVALUE_H_ */

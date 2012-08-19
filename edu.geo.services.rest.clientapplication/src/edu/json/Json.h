/*
 * JSON.h
 *
 *  Created on: Aug 18, 2012
 *      Author: developer
 */

#ifndef JSON_H_
#define JSON_H_

#include <libjson/JSONOptions.h>
#include <libjson/libjson.h>
#include <libjson/Source/JSONNode.h>

namespace edu
{
namespace json
{

enum JsonType
{
	JsonTypeNull = 0, JsonTypeString = 1, JsonTypeNumber = 2, JsonTypeBool = 3, JsonTypeArray = 4, JsonTypeNode = 5
};

}
}

#endif /* JSON_H_ */

/*
 * JsonParser.h
 *
 *  Created on: Aug 18, 2012
 *      Author: developer
 */

#ifndef JSONPARSER_H_
#define JSONPARSER_H_

#include <memory>
#include <string>

#include "Json.h"
#include "JsonNode.h"
#include "JsonNodeVisitor.h"

using namespace std;

namespace edu
{
namespace json
{

class JsonParser
{
private:
	JsonParser();
	~JsonParser();

public:
	static auto_ptr<JsonNode> parse(const string &json);
	static void apply(const JsonNode &node, JsonNodeVisitor &visitor);
};

} /* namespace json */
} /* namespace edu */
#endif /* JSONPARSER_H_ */

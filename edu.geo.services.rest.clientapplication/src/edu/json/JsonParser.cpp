/*
 * JsonParser.cpp
 *
 *  Created on: Aug 18, 2012
 *      Author: developer
 */

#include "JsonParser.h"

namespace edu
{
namespace json
{

auto_ptr<JsonNode> JsonParser::parse(const string &json)
{
	JSONNODE *node = json_parse(json.c_str());
	if (NULL == node)
	{
		throw logic_error("This is not a valid JSON string!");
	}

	auto_ptr<JsonNode> jsonNode(new JsonNode(node));
	return jsonNode;
}

void JsonParser::apply(const JsonNode &node, JsonNodeVisitor &visitor)
{
	JSONNODE_ITERATOR iterator = json_begin(node);
	while (iterator != json_end(node))
	{
		JSONNODE *nextNode = *iterator;
		if (NULL == nextNode)
		{
			throw logic_error("This JSON node contains at least one invalid sub node!");
		}

		JsonNode nextJsonNode(nextNode, false);
		JsonType jsonType = nextJsonNode.type();
		VisitResult result = visitor.visit(nextJsonNode);
		switch (result)
		{
		case ContinueVisiting:
			if (JsonTypeNull != jsonType)
			{
				apply(nextJsonNode, visitor);
			}
			++iterator;
			break;
		case BreakVisiting:
		default:
			return;
		}
	}
}

} /* namespace json */
} /* namespace edu */

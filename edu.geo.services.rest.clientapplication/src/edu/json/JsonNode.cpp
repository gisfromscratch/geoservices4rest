/*
 * JsonNode.cpp
 *
 *  Created on: Aug 18, 2012
 *      Author: developer
 */

#include "JsonNode.h"
#include "JsonNullValue.h"
#include "JsonNumberValue.h"
#include "JsonStringValue.h"

namespace edu
{
namespace json
{

JsonNode::JsonNode(JSONNODE *node, bool takeOwnerShip) :
		_node(node), _deleteNode(takeOwnerShip)
{
	if (NULL != _node)
	{
		_name = json_name(node);
		_type = parseType();
	}
}

JsonNode::~JsonNode()
{
	if (NULL != _node)
	{
		json_free(_name);
		if (_deleteNode)
		{
			json_delete(_node);
		}
	}
}

JsonNode::operator JSONNODE* const() const
{
	return _node;
}

json_char* const JsonNode::name() const
{
	return _name;
}

JsonType JsonNode::type() const
{
	return _type;
}

string JsonNode::typeAsString() const
{
	switch (_type)
	{
	case JsonTypeString:
		return "JsonTypeString";
	case JsonTypeNumber:
		return "JsonTypeNumber";
	case JsonTypeBool:
		return "JsonTypeBool";
	case JsonTypeArray:
		return "JsonTypeArray";
	case JsonTypeNode:
		return "JsonTypeNode";
	default:
		return "JsonTypeNull";
	}
}

auto_ptr<JsonValue> JsonNode::value() const
{
	switch (_type)
	{
	case JsonTypeString:
	{
		auto_ptr<JsonValue> stringValue(new JsonStringValue(*this));
		return stringValue;
	}
	case JsonTypeNumber:
	{
		auto_ptr<JsonValue> numberValue(new JsonNumberValue(*this));
		return numberValue;
	}
	default:
	{
		auto_ptr<JsonValue> nullValue(new JsonNullValue);
		return nullValue;
	}
	}
}

JsonType JsonNode::parseType()
{
	char type = json_type(_node);
	switch (type)
	{
	case JSON_STRING:
		return JsonTypeString;
	case JSON_NUMBER:
		return JsonTypeNumber;
	case JSON_BOOL:
		return JsonTypeBool;
	case JSON_ARRAY:
		return JsonTypeArray;
	case JSON_NODE:
		return JsonTypeNode;
	default:
		return JsonTypeNull;
	}
}

} /* namespace json */
} /* namespace edu */

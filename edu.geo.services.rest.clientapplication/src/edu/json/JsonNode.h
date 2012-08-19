/*
 * JsonNode.h
 *
 *  Created on: Aug 18, 2012
 *      Author: developer
 */

#ifndef JSONNODE_H_
#define JSONNODE_H_

#include <memory>
#include <string>

#include "Json.h"
#include "JsonValue.h"

using namespace std;

namespace edu
{
namespace json
{

class JsonNode {
public:
	JsonNode(JSONNODE *node, bool takeOwnership = true);
	~JsonNode();

	operator JSONNODE* const () const;

	json_char* const name() const;
	JsonType type() const;
	string typeAsString() const;

	auto_ptr<JsonValue> value() const;

private:
	JsonType parseType();

	JSONNODE *_node;
	json_char *_name;
	JsonType _type;

	bool _deleteNode;
};

} /* namespace json */
} /* namespace edu */
#endif /* JSONNODE_H_ */

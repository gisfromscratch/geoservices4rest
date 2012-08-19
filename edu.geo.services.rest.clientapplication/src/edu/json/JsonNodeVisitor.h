/*
 * JsonNodeVisitor.h
 *
 *  Created on: Aug 18, 2012
 *      Author: developer
 */

#ifndef JSONNODEVISITOR_H_
#define JSONNODEVISITOR_H_

#include "JsonNode.h"

namespace edu
{
namespace json
{

enum VisitResult { ContinueVisiting = 0, BreakVisiting = 1 };

class JsonNodeVisitor
{
public:
	JsonNodeVisitor();
	virtual ~JsonNodeVisitor();

	virtual VisitResult visit(const JsonNode &node) = 0;
};

} /* namespace json */
} /* namespace edu */
#endif /* JSONNODEVISITOR_H_ */

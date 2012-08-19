#include <iostream>
#include <memory>
#include <string>

#include "src/edu/json/Json.h"
#include "src/edu/json/JsonParser.h"
#include "src/edu/json/JsonNodeVisitor.h"
#include "src/edu/json/JsonValue.h"
#include "src/edu/json/JsonNullValue.h"
#include "src/edu/json/JsonNumberValue.h"
#include "src/edu/json/JsonStringValue.h"

using namespace std;
using namespace edu::json;

class JsonNodeConsoleVisitor: public JsonNodeVisitor
{
public:
	VisitResult visit(const JsonNode &node)
	{
		cout << "Name:" << node.name() << endl;
		cout << "Type:" << node.typeAsString() << endl;
		auto_ptr<JsonValue> value = node.value();
		JsonStringValue *stringValue = dynamic_cast<JsonStringValue*>(value.get());
		if (NULL != stringValue)
		{
			cout << "StringValue:" << stringValue->toString() << endl;
			return ContinueVisiting;
		}

		JsonNumberValue *numberValue = dynamic_cast<JsonNumberValue*>(value.get());
		if (NULL != numberValue)
		{
			cout << "NumberValue:" << numberValue->toString() << endl;
			return ContinueVisiting;
		}

		JsonNullValue *nullValue = dynamic_cast<JsonNullValue*>(value.get());
		if (NULL != nullValue)
		{
			cout << "NullValue:" << nullValue->toString() << endl;
			return ContinueVisiting;
		}

		return ContinueVisiting;
	}
};

int main()
{
	cout << "Simple REST client" << endl;

	string json =
			"{\"currentVersion\":10.01,\"folders\":[\"Canvas\",\"Demographics\",\"Elevation\",\"Reference\",\"Specialty\"],\"services\":[{\"name\":\"ESRI_Imagery_World_2D\",\"type\":\"MapServer\"},{\"name\":\"ESRI_StreetMap_World_2D\",\"type\":\"MapServer\"},{\"name\":\"I3_Imagery_Prime_World\",\"type\":\"GlobeServer\"},{\"name\":\"NASA_CloudCover_World\",\"type\":\"GlobeServer\"},{\"name\":\"NatGeo_World_Map\",\"type\":\"MapServer\"},{\"name\":\"NGS_Topo_US_2D\",\"type\":\"MapServer\"},{\"name\":\"Ocean_Basemap\",\"type\":\"MapServer\"},{\"name\":\"USA_Topo_Maps\",\"type\":\"MapServer\"},{\"name\":\"World_Imagery\",\"type\":\"MapServer\"},{\"name\":\"World_Physical_Map\",\"type\":\"MapServer\"},{\"name\":\"World_Shaded_Relief\",\"type\":\"MapServer\"},{\"name\":\"World_Street_Map\",\"type\":\"MapServer\"},{\"name\":\"World_Terrain_Base\",\"type\":\"MapServer\"},{\"name\":\"World_Topo_Map\",\"type\":\"MapServer\"}]}";
//	json = "{\"RootA\":\"Value in parent node\",\"ChildNode\":{\"ChildA\":\"String Value\",\"ChildB\":42}}";
	cout << json << endl;

	auto_ptr<JsonNode> jsonRootNode = JsonParser::parse(json);
	JsonNodeConsoleVisitor visitor;
	JsonParser::apply(*jsonRootNode, visitor);

//	parseJson(node);
}

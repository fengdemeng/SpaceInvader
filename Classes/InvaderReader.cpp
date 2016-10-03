#include "InvaderReader.h"
#include "Invader.h"

using namespace cocos2d;

static InvaderReader* _instanceInvaderReader = nullptr;

InvaderReader* InvaderReader::getInstance()
{
	if (!_instanceInvaderReader)
	{
		_instanceInvaderReader = new InvaderReader();
	}
	return _instanceInvaderReader;
}

void InvaderReader::purge()
{
	CC_SAFE_DELETE(_instanceInvaderReader);
}

Node* InvaderReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	Invader* node = Invader::create();
	setPropsWithFlatBuffers(node, nodeOptions);
	return node;
}
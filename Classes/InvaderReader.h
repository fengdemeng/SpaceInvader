#ifndef INVADERREADER_H
#define INVADERREADER_H

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

//	singleton class for customn Invader class
class InvaderReader : public cocostudio::NodeReader
{
public:
	static InvaderReader* getInstance();
	static void purge();
	cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif


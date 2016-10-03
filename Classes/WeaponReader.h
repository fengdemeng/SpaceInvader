#ifndef WEAPONREADER_H
#define WEAPONREADER_H

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

//	singleton class for customn Invader class
class WeaponReader : public cocostudio::NodeReader
{
public:
	static WeaponReader* getInstance();
	static void purge();
	cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};
#endif


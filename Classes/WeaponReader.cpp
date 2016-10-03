#include "WeaponReader.h"
#include "Weapon.h"

using namespace cocos2d;

static WeaponReader* _instanceWeaponReader = nullptr;

WeaponReader* WeaponReader::getInstance()
{
	if (!_instanceWeaponReader)
	{
		_instanceWeaponReader = new WeaponReader();
	}
	return _instanceWeaponReader;
}

void WeaponReader::purge()
{
	CC_SAFE_DELETE(_instanceWeaponReader);
}

Node* WeaponReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	Weapon* node = Weapon::create();
	setPropsWithFlatBuffers(node, nodeOptions);
	return node;
}

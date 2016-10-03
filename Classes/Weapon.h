#ifndef WEAPON_H
#define WEAPON_H

#include "cocos2d.h"
#include "Constants.h"

class Weapon : public cocos2d::Node
{
public:
	CREATE_FUNC(Weapon);
	void setWeaponType(WeaponType weaponType);
	void setWeaponShape(cocos2d::Sprite* weaponShape);
	cocos2d::Sprite* getWeaponShape();
	WeaponType getWeaponType();
private:
	WeaponType weaponType;	//	enemy, player
	cocos2d::Sprite* weaponShape;	//	used to calculate weapon's size
};
#endif


#include "Weapon.h"

void Weapon::setWeaponType(WeaponType weaponType)
{
	this->weaponType = weaponType;
}

void Weapon::setWeaponShape(cocos2d::Sprite * weaponShape)
{
	this->weaponShape = weaponShape;
}

cocos2d::Sprite * Weapon::getWeaponShape()
{
	return this->weaponShape;
}

WeaponType Weapon::getWeaponType()
{
	return this->weaponType;
}

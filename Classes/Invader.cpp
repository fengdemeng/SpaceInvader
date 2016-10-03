#include "Invader.h"

void Invader::setShape(cocos2d::Sprite * shape1, cocos2d::Sprite * shape2, cocos2d::Sprite * explosion)
{
	this->shape1 = shape1;
	this->shape2 = shape2;
	this->explosion = explosion;
}

void Invader::setShape1Visible(bool shape1Visible)
{
	this->shape1Visible = shape1Visible;
	this->shape1->setVisible(shape1Visible);
}

void Invader::setShape2Visible(bool shape2Visible)
{
	this->shape2Visible = shape2Visible;
	this->shape2->setVisible(shape2Visible);
}

void Invader::setExplosionVisible(bool explosionVisible)
{
	this->explosionVisible = explosionVisible;
	this->explosion->setVisible(explosionVisible);
}

void Invader::setDestroyed(bool destroyed)
{
	this->destroyed = destroyed;
}

cocos2d::Sprite * Invader::getShape()
{
	return this->shape1;
}

bool Invader::isShape1Visible()
{
	return this->shape1Visible;
}

bool Invader::isShape2Visible()
{
	return this->shape2Visible;
}

bool Invader::isExplosion()
{
	return this->explosionVisible;
}

bool Invader::isdestroyed()
{
	return this->destroyed;
}

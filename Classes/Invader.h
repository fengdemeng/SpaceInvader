#ifndef INVADER_H
#define INVADER_H

#include "cocos2d.h"

class Invader : public cocos2d::Node
{
public:
	CREATE_FUNC(Invader);
	void setShape(cocos2d::Sprite* shape1, cocos2d::Sprite* shape2, cocos2d::Sprite* explosion );
	void setShape1Visible(bool shape1Visible);
	void setShape2Visible(bool shape2Visible);
	void setExplosionVisible(bool explosionVisible);
	void setDestroyed(bool destroyed);
	cocos2d::Sprite* getShape();
	bool isShape1Visible();
	bool isShape2Visible();
	bool isExplosion();
	bool isdestroyed();
private:
	cocos2d::Sprite* shape1;	//	record invaders shape1 shape2 and explosion
	cocos2d::Sprite* shape2;
	cocos2d::Sprite* explosion;
	bool shape1Visible;
	bool shape2Visible;
	bool explosionVisible;
	bool destroyed;
};

#endif


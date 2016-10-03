#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "Constants.h"
#include "Invader.h"
#include "Weapon.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class HelloWorld : public cocos2d::Layer {
public:
  // there's no 'id' in cpp, so we recommend returning the class instance
  // pointer
  static cocos2d::Scene *createScene();

  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of
  // returning 'id' in cocos2d-iphone
  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(HelloWorld);

  void onEnter() override;

private:
  cocos2d::Node *enemyNode; //	control invaders movement
  cocos2d::Node *rootNode;
  cocos2d::Vector<Invader *> invaders;
  cocos2d::Vector<Invader *> frontInvaders; //	record invaders which can attack
  int numOfFrontInvaders;
  cocos2d::Vector<Weapon *> Weapons; //	player and invaders missle, ray
  MoveDirection movedirection;
  GameState gamestate;
  cocos2d::ui::Text *startLabel;
  cocos2d::ui::Text *scoreLabel;
  cocos2d::ui::Text *score;
  int scoreRecord;
  cocos2d::Sprite *spaceShip;
  cocos2d::Vector<cocos2d::Sprite *> shields;
  cocos2d::Node *gameOverPanel;
  cocos2d::ui::Text *finalScore;

  void setupTouchHandling(); // touch control
  void triggerPlaying();
  void resetGame();
  void triggerGameover();
  int getScore();
  void setScore(int score);
  void invadersRun(float dt);    //	move the invader array
  void invadersAttack(float dt); // invadersAttack
  void playerLaunchWeapon(float x, float y);
  void enemyLaunchWeapon(float x, float y);
  void weaponMove(float dt);     //	move player's and invaders' weapons
  void spaceShipCheck(float dt); //	check whether spaceShip is shot
  void shieldsCheck(float dt);   //	check whether shields are attacked
  void invadersCheck(float dt);  //	check whether invaders are attacked
  void invadersExplosion(Invader *invader); //	let invader explose
  bool isIntersect(float lx1, float ly1, float ux1, float uy1, float lx2,
                   float ly2, float ux2, float uy2); //	check intersected
  void updateFrontInvaders(); //	update frontInvaders vector
  void isOver();              //	whether game is over
  void onAcceleration(cocos2d::Acceleration *acc,
                      cocos2d::Event *event); //	accelerator contrl
};

#endif // __HELLOWORLD_SCENE_H__

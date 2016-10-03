#include "HelloWorldScene.h"
#include "InvaderReader.h"
#include "WeaponReader.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene *HelloWorld::createScene() {
  // 'scene' is an autorelease object
  auto scene = Scene::create();

  // 'layer' is an autorelease object
  auto layer = HelloWorld::create();

  // add layer as a child to scene
  scene->addChild(layer);

  // return the scene
  return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
  /**  you can create scene with following comment code instead of using csb
  file.
  // 1. super init first
  if ( !Layer::init() )
  {
      return false;
  }

  Size visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  /////////////////////////////
  // 2. add a menu item with "X" image, which is clicked to quit the program
  //    you may modify it.

  // add a "close" icon to exit the progress. it's an autorelease object
  auto closeItem = MenuItemImage::create(
                                         "CloseNormal.png",
                                         "CloseSelected.png",
                                         CC_CALLBACK_1(HelloWorld::menuCloseCallback,
  this));

      closeItem->setPosition(Vec2(origin.x + visibleSize.width -
  closeItem->getContentSize().width/2 ,
                              origin.y + closeItem->getContentSize().height/2));

  // create menu, it's an autorelease object
  auto menu = Menu::create(closeItem, NULL);
  menu->setPosition(Vec2::ZERO);
  this->addChild(menu, 1);

  /////////////////////////////
  // 3. add your codes below...

  // add a label shows "Hello World"
  // create and initialize a label

  auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

  // position the label on the center of the screen
  label->setPosition(Vec2(origin.x + visibleSize.width/2,
                          origin.y + visibleSize.height -
  label->getContentSize().height));

  // add the label as a child to this layer
  this->addChild(label, 1);

  // add "HelloWorld" splash screen"
  auto sprite = Sprite::create("HelloWorld.png");

  // position the sprite on the center of the screen
  sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2
  + origin.y));

  // add the sprite as a child to this layer
  this->addChild(sprite, 0);
  **/

  //////////////////////////////
  // 1. super init first
  if (!Layer::init()) {
    return false;
  }
  // Register the readers for our custom classes
  // Be very careful to do CharacterReader::getInstance, not
  // CharacterReader::getInstance() which will crash
  CSLoader *instance = CSLoader::getInstance();
  instance->registReaderObject(
      "InvaderReader", (ObjectFactory::Instance)InvaderReader::getInstance);
  instance->registReaderObject(
      "WeaponReader", (ObjectFactory::Instance)WeaponReader::getInstance);

  rootNode = CSLoader::createNode("MainScene.csb");

  // Display correctly
  Size size = Director::getInstance()->getVisibleSize();
  rootNode->setContentSize(size);
  ui::Helper::doLayout(rootNode);

  // Initialize enemyNode;
  this->enemyNode = rootNode->getChildByName("enemyNode");

  // Initialize move direction and game state
  this->movedirection = MoveDirection::none;
  this->gamestate = GameState::title;

  // Initialize start label and score label
  this->startLabel =
      rootNode->getChildByName<cocos2d::ui::Text *>("startLabel");
  this->score = rootNode->getChildByName<cocos2d::ui::Text *>("score");
  this->scoreLabel =
      rootNode->getChildByName<cocos2d::ui::Text *>("scoreLabel");
  this->scoreRecord = 0;

  // Initialize spaceship
  this->spaceShip = rootNode->getChildByName<cocos2d::Sprite *>("spaceShip");

  // Initialize shields
  cocos2d::Sprite *shield =
      rootNode->getChildByName<cocos2d::Sprite *>("shield1");
  this->shields.pushBack(shield);
  shield = rootNode->getChildByName<cocos2d::Sprite *>("shield2");
  this->shields.pushBack(shield);
  shield = rootNode->getChildByName<cocos2d::Sprite *>("shield3");
  this->shields.pushBack(shield);
  shield = rootNode->getChildByName<cocos2d::Sprite *>("shield4");
  this->shields.pushBack(shield);

  // Initialize game over panel
  this->gameOverPanel = rootNode->getChildByName("gameOverPanel");

  // Initialize final score label
  this->finalScore =
      this->gameOverPanel->getChildByName<cocos2d::ui::Text *>("finalScore");

  // Initialize enemy in the front
  numOfFrontInvaders = 0;
  // Initialize enemy array;
  for (int row = 0; row < ROWs; row++) {
    for (int col = 0; col < COLs; col++) {

      Invader *invader = nullptr;
      switch (row) {
      case 0:
        invader = dynamic_cast<Invader *>(CSLoader::createNode("InvaderA.csb"));
        frontInvaders.pushBack(invader);
        numOfFrontInvaders++;
        break;
      case 1:
        invader = dynamic_cast<Invader *>(CSLoader::createNode("InvaderB.csb"));
        break;
      case 2:
        invader = dynamic_cast<Invader *>(CSLoader::createNode("InvaderC.csb"));
        break;
      }
      cocos2d::Sprite *shape1 =
          invader->getChildByName<cocos2d::Sprite *>("shape1");
      cocos2d::Sprite *shape2 =
          invader->getChildByName<cocos2d::Sprite *>("shape2");
      cocos2d::Sprite *explosion =
          invader->getChildByName<cocos2d::Sprite *>("explosion");
      invader->setShape(shape1, shape2, explosion);
      invader->setShape1Visible(false);
      invader->setShape2Visible(false);
      invader->setExplosionVisible(false);
      invader->setDestroyed(false);
      invader->setPosition(0.0f + col * 60.0f, 0.0f + row * 60.0f);
      this->enemyNode->addChild(invader);
      invaders.pushBack(invader);
    }
  }

  addChild(rootNode);

  // enable accelerator

  Device::setAccelerometerEnabled(true);

  // creating an accelerometer event
  auto listener = EventListenerAcceleration::create(
      CC_CALLBACK_2(HelloWorld::onAcceleration, this));
  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

  return true;
}

void HelloWorld::onEnter() {
  Layer::onEnter();
  this->setupTouchHandling();
}

void HelloWorld::setupTouchHandling() {
  auto touchListener = EventListenerTouchOneByOne::create();

  touchListener->onTouchBegan = [&](Touch *touch, Event *event) {
    switch (this->gamestate) {
    case GameState::title:
      this->triggerPlaying(); // start the game when touch screen during title
      break;
    case GameState::playing:
      //	launch weapon when touch screen during game
      this->playerLaunchWeapon(this->spaceShip->getPositionX(),
                               this->spaceShip->getPositionY());
      break;
    case GameState::gameover:
      this->triggerPlaying(); //	restart the game when touch scrren
      // during game over
      break;
    }

    return true;
  };

  this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
      touchListener, this);
}

void HelloWorld::triggerPlaying() {
  this->resetGame();
  this->gamestate = GameState::playing;

  //	let invader run and attack, let weapon can move
  this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::invadersRun), 0.25f);
  this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::weaponMove), 0.25f);
  this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::invadersAttack), 0.25f);

  //	check whether is attacked
  this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::spaceShipCheck), 0.1f);
  this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::invadersCheck), 0.1f);
  this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::shieldsCheck), 0.1f);
}

void HelloWorld::resetGame() {
  this->startLabel->setVisible(false);
  this->enemyNode->setPosition(
      Vec2(102.4f, 460.8f)); //	reset the invaders position

  //	reset invader and invaders vector
  for (int i = 0; i < invaders.size(); i++) {
    Invader *invader = this->invaders.at(i);
    invader->setShape1Visible(true);
    invader->setShape2Visible(false);
    invader->setExplosionVisible(false);
    invader->setDestroyed(false);
  }
  this->enemyNode->setVisible(true);

  //	reset score and label
  this->setScore(0);
  this->scoreLabel->setVisible(true);
  this->score->setVisible(true);
  this->spaceShip->setVisible(true);
  //	reset shield and shields vector
  for (int i = 0; i < 4; i++) {
    Sprite *shield = this->shields.at(i);
    shield->setVisible(true);
  }
  this->gameOverPanel->setVisible(false);
  this->movedirection = MoveDirection::right;

  //	reset weapons vector
  for (int i = 0; i < Weapons.size(); i++)
    rootNode->removeChild(Weapons.at(i));
  Weapons.clear();

  //	reset frontInvaders vector
  frontInvaders.clear();
  for (int i = 0; i < COLs; i++)
    frontInvaders.pushBack(invaders.at(i));
  this->numOfFrontInvaders = COLs;
}

void HelloWorld::triggerGameover() {
  this->gamestate = GameState::gameover;
  this->movedirection = MoveDirection::none;
  this->enemyNode->setVisible(false);
  this->scoreLabel->setVisible(false);
  this->score->setVisible(false);
  this->setScore(getScore());
  this->gameOverPanel->setVisible(true);

  //	stop move
  this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::invadersRun));
  this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::weaponMove));
  this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::invadersAttack));
  this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::spaceShipCheck));
  this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::invadersCheck));
  this->unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::shieldsCheck));
}

int HelloWorld::getScore() { return scoreRecord; }

void HelloWorld::setScore(int score) {
  this->scoreRecord = score;
  this->score->setString(std::to_string(score));
  this->finalScore->setString(std::to_string(score));
}

void HelloWorld::invadersRun(float dt) {
  //	update invaders shape like moving and explosing
  for (int i = 0; i < invaders.size(); i++) {
    Invader *invader = this->invaders.at(i);
    // change direction
    if ((enemyNode->getPositionX() + invader->getPositionX() + 60.0f) >
        921.6f) {
      movedirection = MoveDirection::left;
    }
    if ((enemyNode->getPositionX() + invader->getPositionX()) <
        102.4f) //	go right or down
    {
      if (enemyNode->getPositionY() + invader->getPositionY() > 230.0f &&
          movedirection == MoveDirection::left) {
        movedirection = MoveDirection::down;
        break;
      } else
        movedirection = MoveDirection::right;
    }

    //	change invaders' shape to let it "run"
    if (!invader->isdestroyed() && !invader->isExplosion()) {
      invader->setShape1Visible(!invader->isShape1Visible());
      invader->setShape2Visible(!invader->isShape2Visible());
    } else if (invader->isExplosion()) {
      invader->setDestroyed(true);
      invader->setExplosionVisible(false);
      invader->setShape1Visible(false);
      invader->setShape2Visible(false);
    } else {
      invader->setShape1Visible(false);
      invader->setShape2Visible(false);
      invader->setExplosionVisible(false);
    }
  }

  //	decide which direction to go
  cocos2d::MoveBy *moveAction;
  switch (movedirection) {
  case MoveDirection::right:
    moveAction = cocos2d::MoveBy::create(0.25f, Vec2(10.0f, 0.0f));
    break;
  case MoveDirection::left:
    moveAction = cocos2d::MoveBy::create(0.25f, Vec2(-10.0f, 0.0f));
    break;
  case MoveDirection::down:
    moveAction = cocos2d::MoveBy::create(0.25f, Vec2(0.0f, -60.0f));
    break;
  }
  this->enemyNode->runAction(moveAction);
}

void HelloWorld::invadersAttack(float dt) {
  for (int i = 0; i < frontInvaders.size(); i++) {
    //	randomly attack
    float random = CCRANDOM_0_1();
    if (!frontInvaders.at(i)->isdestroyed() &&
        random < 0.05f / numOfFrontInvaders) {
      float x = frontInvaders.at(i)->getPositionX() +
                enemyNode->getPositionX() +
                frontInvaders.at(i)->getShape()->getContentSize().width / 2.0f;
      float y = frontInvaders.at(i)->getPositionY() + enemyNode->getPositionY();
      this->enemyLaunchWeapon(x, y);
      break;
    }
  }
}

void HelloWorld::playerLaunchWeapon(float x, float y) {
  Weapon *playerWeapon =
      dynamic_cast<Weapon *>(CSLoader::createNode("PlayerMissle.csb"));
  cocos2d::Sprite *weaponShape =
      playerWeapon->getChildByName<cocos2d::Sprite *>("playerMissle");
  playerWeapon->setPosition(x, y);
  playerWeapon->setWeaponType(WeaponType::player);
  playerWeapon->setWeaponShape(weaponShape);
  this->rootNode->addChild(playerWeapon);
  this->Weapons.pushBack(playerWeapon);
}

void HelloWorld::enemyLaunchWeapon(float x, float y) {
  float random = CCRANDOM_0_1();
  Weapon *enemyWeapon = nullptr;
  cocos2d::Sprite *weaponShape = nullptr;
  //	invader randomly launch weapons
  if (random < 0.5f) {
    enemyWeapon =
        dynamic_cast<Weapon *>(CSLoader::createNode("EnemyMissle.csb"));
    weaponShape = enemyWeapon->getChildByName<cocos2d::Sprite *>("enemyMissle");
  } else {
    enemyWeapon = dynamic_cast<Weapon *>(CSLoader::createNode("EnemyRay.csb"));
    weaponShape = enemyWeapon->getChildByName<cocos2d::Sprite *>("enemyRay");
  }
  enemyWeapon->setPosition(x, y);
  enemyWeapon->setWeaponType(WeaponType::enemy);
  enemyWeapon->setWeaponShape(weaponShape);
  this->rootNode->addChild(enemyWeapon);
  this->Weapons.pushBack(enemyWeapon);
}

void HelloWorld::weaponMove(float dt) {
  //	move weapons
  for (int i = 0; i < this->Weapons.size();) {
    //	eliminate weapons which get to the edge
    if (Weapons.at(i)->getPositionY() > 700.0f ||
        Weapons.at(i)->getPositionY() < 60.0f) {
      rootNode->removeChild(Weapons.at(i));
      Weapons.erase(i);
      continue;
    }
    cocos2d::MoveBy *moveAction = nullptr;
    //	invaders' weapon move up down, player's weapon move down up
    if (Weapons.at(i)->getWeaponType() == WeaponType::enemy)
      moveAction = cocos2d::MoveBy::create(0.25f, Vec2(0.0f, -80.0f));
    else
      moveAction = cocos2d::MoveBy::create(0.25f, Vec2(0.0f, 80.0f));
    Weapons.at(i)->runAction(moveAction);
    i++;
  }
}

void HelloWorld::spaceShipCheck(float dt) {
  //	get (lx1, ly1), (ux1, uy1) of spach ship
  float lx1 =
      spaceShip->getPositionX() - spaceShip->getContentSize().width / 2.0f;
  float ux1 =
      spaceShip->getPositionX() + spaceShip->getContentSize().width / 2.0f;
  float ly1 = spaceShip->getPositionY();
  float uy1 = spaceShip->getPositionY() + spaceShip->getContentSize().height;
  for (int i = 0; i < Weapons.size(); i++) {
    // get enemy weapons' (lx2, ly2), (ux2, uy2)
    if (Weapons.at(i)->getWeaponType() == WeaponType::enemy) {
      float lx2 =
          Weapons.at(i)->getPositionX() -
          Weapons.at(i)->getWeaponShape()->getContentSize().width / 2.0f;
      float ux2 =
          Weapons.at(i)->getPositionX() +
          Weapons.at(i)->getWeaponShape()->getContentSize().width / 2.0f;
      float ly2 = Weapons.at(i)->getPositionY() -
                  Weapons.at(i)->getWeaponShape()->getContentSize().height;
      float uy2 = Weapons.at(i)->getPositionY();
      //	if intersected eliminate
      if (isIntersect(lx1, ly1, ux1, uy1, lx2, ly2, ux2, uy2)) {
        this->triggerGameover();
        return;
      }
    }
  }
}

void HelloWorld::shieldsCheck(float dt) {
  for (int i = 0; i < shields.size(); i++) {
    if (shields.at(i)->isVisible()) {
      //	get (lx1, ly1), (ux1, uy1) of shield
      float lx1 = shields.at(i)->getPositionX() -
                  shields.at(i)->getContentSize().width / 2.0f;
      float ux1 = shields.at(i)->getPositionX() +
                  shields.at(i)->getContentSize().width / 2.0f;
      float ly1 = shields.at(i)->getPositionY();
      float uy1 = shields.at(i)->getPositionY() +
                  shields.at(i)->getContentSize().height;
      for (int j = 0; j < Weapons.size();) {
        // get weapons' (lx2, ly2), (ux2, uy2)
        float lx2, ux2, ly2, uy2;
        if (Weapons.at(j)->getWeaponType() == WeaponType::enemy) {
          lx2 = Weapons.at(j)->getPositionX() -
                Weapons.at(j)->getWeaponShape()->getContentSize().width / 2.0f;
          ux2 = Weapons.at(j)->getPositionX() +
                Weapons.at(j)->getWeaponShape()->getContentSize().width / 2.0f;
          ly2 = Weapons.at(j)->getPositionY() -
                Weapons.at(j)->getWeaponShape()->getContentSize().height;
          uy2 = Weapons.at(j)->getPositionY();
        } else {
          lx2 = Weapons.at(j)->getPositionX() -
                Weapons.at(j)->getWeaponShape()->getContentSize().width / 2.0f;
          ux2 = Weapons.at(j)->getPositionX() +
                Weapons.at(j)->getWeaponShape()->getContentSize().width / 2.0f;
          ly2 = Weapons.at(j)->getPositionY();
          uy2 = Weapons.at(j)->getPositionY() +
                Weapons.at(j)->getWeaponShape()->getContentSize().height;
        }

        //	if intersected remove shield and weapon
        if (isIntersect(lx1, ly1, ux1, uy1, lx2, ly2, ux2, uy2)) {
          shields.at(i)->setVisible(false);
          rootNode->removeChild(Weapons.at(j));
          Weapons.erase(j);
          continue;
        }
        j++;
      }
    }
  }
}

void HelloWorld::invadersCheck(float dt) {
  for (int i = 0; i < invaders.size(); i++) {
    if (!invaders.at(i)->isdestroyed() && !invaders.at(i)->isExplosion()) {
      //	get (lx1, ly1), (ux1, uy1) for invader
      float lx1 = invaders.at(i)->getPositionX() + enemyNode->getPositionX();
      float ly1 = invaders.at(i)->getPositionY() + enemyNode->getPositionY();
      float ux1 = invaders.at(i)->getPositionX() + enemyNode->getPositionX() +
                  invaders.at(i)->getShape()->getContentSize().width;
      float uy1 = invaders.at(i)->getPositionY() + enemyNode->getPositionY() +
                  invaders.at(i)->getShape()->getContentSize().height;
      for (int j = 0; j < Weapons.size();) {
        // get player weapons' (lx2, ly2), (ux2, uy2)
        float lx2, ux2, ly2, uy2;
        lx2 = ux2 = ly2 = uy2 = 0.0f;
        if (Weapons.at(j)->getWeaponType() == WeaponType::player) {
          lx2 = Weapons.at(j)->getPositionX() -
                Weapons.at(j)->getWeaponShape()->getContentSize().width / 2.0f;
          ux2 = Weapons.at(j)->getPositionX() +
                Weapons.at(j)->getWeaponShape()->getContentSize().width / 2.0f;
          ly2 = Weapons.at(j)->getPositionY();
          uy2 = Weapons.at(j)->getPositionY() +
                Weapons.at(j)->getWeaponShape()->getContentSize().height;
        }
        if (isIntersect(lx1, ly1, ux1, uy1, lx2, ly2, ux2, uy2)) {

          rootNode->removeChild(Weapons.at(j));
          Weapons.erase(j);
          if (!invaders.at(i)->isExplosion() && !invaders.at(i)->isdestroyed())
            setScore(getScore() + 10);
          invadersExplosion(invaders.at(i));
          updateFrontInvaders();
          //	whether the game is over
          isOver();
          continue;
        }
        j++;
      }
    }
  }
}

void HelloWorld::invadersExplosion(Invader *invader) {
  invader->setShape1Visible(false);
  invader->setShape2Visible(false);
  invader->setExplosionVisible(true);
}

bool HelloWorld::isIntersect(float lx1, float ly1, float ux1, float uy1,
                             float lx2, float ly2, float ux2, float uy2) {
  return !(ux1 < lx2 || ux2 < lx1 || ly1 > uy2 || ly2 > uy1);
}

void HelloWorld::updateFrontInvaders() {
  //	update the frontInvaders vector
  for (int i = 0; i < frontInvaders.size(); i++) {
    if (frontInvaders.at(i)->isExplosion()) {
      for (int j = 1; j < ROWs; j++) {
        if (!invaders.at(i + j * COLs)->isdestroyed() &&
            !invaders.at(i + j * COLs)->isExplosion()) {
          frontInvaders.replace(i, invaders.at(i + j * COLs));
          break;
        }
      }
      if (frontInvaders.at(i)->isExplosion())
        this->numOfFrontInvaders--;
    }
  }
}

void HelloWorld::isOver() {
  if (!numOfFrontInvaders)
    triggerGameover();
}

void HelloWorld::onAcceleration(cocos2d::Acceleration *acc,
                                cocos2d::Event *event) {
  if (gamestate != GameState::playing)
    return;
  if (spaceShip->getPositionX() > 100.0f &&
      spaceShip->getPositionX() < 924.0f) {
    cocos2d::MoveBy *moveAction = nullptr;
    if (acc->x < -0.1f) {
      moveAction = cocos2d::MoveBy::create(0.2f, Vec2(-10.0f, 0.0f));
      spaceShip->runAction(moveAction);
    } else if (acc->x > 0.1f) {
      moveAction = cocos2d::MoveBy::create(0.2f, Vec2(10.0f, 0.0f));
      spaceShip->runAction(moveAction);
    }
  }
  else if(spaceShip->getPositionX()<100.0f)
      spaceShip->setPositionX(101.0f);
  else if(spaceShip->getPositionX()>924.0f)
      spaceShip->setPositionX(923.0f);
}

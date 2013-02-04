#ifndef __MOTION_STREAK
#define __MOTION_STREAK
#include "cocos2d.h"

#include "SimpleAudioEngine.h"
#include "testBasic.h"



//Scene
class MotionStreakScene : public TestScene
{
public:
    virtual void runThisTest();
};


//CCLayer
class MotionStreakLayer : public CCLayer
{
protected:
    CCSprite*    spr_s_back;
    
public:
    virtual void onEnter();
    virtual void onExit();

    void centerSprites(unsigned int numberOfSprites);
    void alignSpritesLeft(unsigned int numberOfSprites);
    virtual std::string title();
    virtual std::string subtitle();

	void addSnowMtionStreak();


	float x,y;
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void getLine(cocos2d::CCPoint pt);
};
/*
class PageLayer1 : public PageTurnLayer
{
public:
    virtual void onEnter();
    virtual std::string subtitle();
};
*/

#endif  // __MOTION_STREAK
#ifndef __PAGETURN_SCENE
#define __PAGETURN_SCENE

#include "cocos2d.h"

#include "SimpleAudioEngine.h"
#include "testBasic.h"

enum
{
    PAGELAYER1 = 0,  
	PAGELAYERCOUNT,
};

class PageTurnScene : public TestScene
{
public:
    virtual void runThisTest();
};

class PageTurnLayer : public CCLayer
{
protected:
    CCSprite*    m_grossini;
    CCSprite*    m_tamara;
    CCSprite*    m_kathia;
public:
    virtual void onEnter();
    virtual void onExit();

    void centerSprites(unsigned int numberOfSprites);
    void alignSpritesLeft(unsigned int numberOfSprites);
    virtual std::string title();
    virtual std::string subtitle();
};

class PageLayer1 : public PageTurnLayer
{
public:
    virtual void onEnter();
    virtual std::string subtitle();
};

#endif  // __PAGETURN_SCENE
#ifndef __PAGETURN_SCENE
#define __PAGETURN_SCENE

#include "cocos2d.h"

#include "SimpleAudioEngine.h"
#include "testBasic.h"


class PageTurnScene : public TestScene
{
public:
    virtual void runThisTest();
};

class PageTurnLayer : public CCLayer
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
};
/*
class PageLayer1 : public PageTurnLayer
{
public:
    virtual void onEnter();
    virtual std::string subtitle();
};
*/

#endif  // __PAGETURN_SCENE
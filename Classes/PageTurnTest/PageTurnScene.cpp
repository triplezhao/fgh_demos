#include "PageTurnScene.h"
#include "HelloWorldScene.h"
#include "../testResource.h"
using namespace cocos2d;


CCLayer* NextAction();
CCLayer* BackAction();
CCLayer* RestartAction();

static int s_nActionIdx = -1;

CCLayer* CreateLayer(int nIndex)
{
    CCLayer * pLayer = NULL;

    switch (nIndex)
    {
        case PAGELAYER1:
            pLayer = new PageLayer1(); break;
      
    default:
        break;
    }

    return pLayer;
}

CCLayer* NextAction()
{
    ++s_nActionIdx;
    s_nActionIdx = s_nActionIdx % PAGELAYERCOUNT;

    CCLayer* pLayer = CreateLayer(s_nActionIdx);
    pLayer->autorelease();

    return pLayer;
}

CCLayer* BackAction()
{
    --s_nActionIdx;
    if( s_nActionIdx < 0 )
        s_nActionIdx += PAGELAYERCOUNT;    

    CCLayer* pLayer = CreateLayer(s_nActionIdx);
    pLayer->autorelease();

    return pLayer;
}

CCLayer* RestartAction()
{
    CCLayer* pLayer = CreateLayer(s_nActionIdx);
    pLayer->autorelease();

    return pLayer;
}


void PageTurnScene::runThisTest()
{
    s_nActionIdx = -1;
    addChild(NextAction());

    CCDirector::sharedDirector()->replaceScene(this);
}


std::string PageTurnLayer::title()
{
    return "ActionsTest";
}

std::string PageTurnLayer::subtitle()
{
    return "";
}

void PageTurnLayer::onEnter()
{
    CCLayer::onEnter();

    // Or you can create an sprite using a filename. only PNG is supported now. Probably TIFF too
    m_grossini = CCSprite::create(s_pPathGrossini);
    m_grossini->retain();

    m_tamara = CCSprite::create(s_pPathSister1); 
    m_tamara->retain();

    m_kathia = CCSprite::create(s_pPathSister2);
    m_kathia->retain();

    addChild(m_grossini, 1);
    addChild(m_tamara, 2);
    addChild(m_kathia, 3);

    m_grossini->setPosition(ccp(VisibleRect::center().x, VisibleRect::bottom().y+VisibleRect::getVisibleRect().size.height/3));
    m_tamara->setPosition(ccp(VisibleRect::center().x, VisibleRect::bottom().y+VisibleRect::getVisibleRect().size.height*2/3));
    m_kathia->setPosition(ccp(VisibleRect::center().x, VisibleRect::bottom().y+VisibleRect::getVisibleRect().size.height/2)); 

    // add title and subtitle
    std::string str = title();
    const char * pTitle = str.c_str();
    CCLabelTTF* label = CCLabelTTF::create(pTitle, "Arial", 18);
    addChild(label, 1);
    label->setPosition( ccp(VisibleRect::center().x, VisibleRect::top().y - 30) );

    std::string strSubtitle = subtitle();
    if( ! strSubtitle.empty() ) 
    {
        CCLabelTTF* l = CCLabelTTF::create(strSubtitle.c_str(), "Thonburi", 22);
        addChild(l, 1);
        l->setPosition( ccp(VisibleRect::center().x, VisibleRect::top().y - 60) );
    }    

    // add menu
    CCMenuItemImage *item1 = CCMenuItemImage::create(s_pPathB1, s_pPathB2, this, menu_selector(PageTurnLayer::backCallback) );
    CCMenuItemImage *item2 = CCMenuItemImage::create(s_pPathR1, s_pPathR2, this, menu_selector(PageTurnLayer::restartCallback) );
    CCMenuItemImage *item3 = CCMenuItemImage::create(s_pPathF1, s_pPathF2, this, menu_selector(PageTurnLayer::nextCallback) );

    CCMenu *menu = CCMenu::create(item1, item2, item3, NULL);

    menu->setPosition(CCPointZero);
    item1->setPosition(ccp(VisibleRect::center().x - item2->getContentSize().width*2, VisibleRect::bottom().y+item2->getContentSize().height/2));
    item2->setPosition(ccp(VisibleRect::center().x, VisibleRect::bottom().y+item2->getContentSize().height/2));
    item3->setPosition(ccp(VisibleRect::center().x + item2->getContentSize().width*2, VisibleRect::bottom().y+item2->getContentSize().height/2));

    addChild(menu, 1);
}

//------------------------------------------------------------------
//
// ActionManual
//
//------------------------------------------------------------------
void PageLayer1::onEnter()
{
    PageTurnLayer::onEnter();

    CCSize s = CCDirector::sharedDirector()->getWinSize();

    m_tamara->setScaleX( 2.5f);
    m_tamara->setScaleY( -1.0f);
    m_tamara->setPosition( ccp(100,70) );
    m_tamara->setOpacity( 128);

    m_grossini->setRotation( 120);
    m_grossini->setPosition( ccp(s.width/2, s.height/2));
    m_grossini->setColor( ccc3( 255,0,0));

    m_kathia->setPosition( ccp(s.width-100, s.height/2));
    m_kathia->setColor( ccBLUE);
}

std::string PageLayer1::subtitle()
{
    return "Manual Transformation";
}



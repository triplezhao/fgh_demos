#include "PageTurnScene.h"
#include "HelloWorldScene.h"
#include "../testResource.h"
using namespace cocos2d;




void PageTurnScene::runThisTest()
{
   //CCLayer* pLayer =   pLayer = new PageLayer1();
   CCLayer* pLayer =   pLayer = new PageTurnLayer(); 
	addChild(pLayer);

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
    spr_s_back = CCSprite::create(s_back);
    addChild(spr_s_back);


	//add page turn action

	int x,y;
	x=16;
	y=12;
	CCActionInterval *action  =  CCPageTurn3D::create(ccg(x,y), 2);
	spr_s_back->runAction(action);

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

	
}

void PageTurnLayer::onExit()
{
   

    CCLayer::onExit();
}

//------------------------------------------------------------------
//
// ActionManual
//
//------------------------------------------------------------------
/*
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
	*/
/*
std::string PageLayer1::subtitle()
{
    return "Manual Transformation";
}
*/



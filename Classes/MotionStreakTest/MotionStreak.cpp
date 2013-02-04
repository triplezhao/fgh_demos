#include "MotionStreak.h"
#include "HelloWorldScene.h"
#include "../testResource.h"
using namespace cocos2d;




void MotionStreakScene::runThisTest()
{
	//CCLayer* pLayer =   pLayer = new PageLayer1();
	MotionStreakLayer* pLayer = new MotionStreakLayer(); 
	addChild(pLayer);
	pLayer->addSnowMtionStreak();

	CCDirector::sharedDirector()->replaceScene(this);
}


std::string MotionStreakLayer::title()
{
    return "MotionStreakTest";
}

std::string MotionStreakLayer::subtitle()
{
    return "";
}

void MotionStreakLayer::onEnter()
{
    CCLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);  

	CCSprite *spr_bg=CCSprite::create("Images/snowbg.jpg");
	//spr_bg->setAnchorPoint(ccp(0,0));
	spr_bg->setPosition(ccp(VisibleRect::center().x, VisibleRect::center().y));
	addChild(spr_bg,0);

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

void MotionStreakLayer::onExit()
{
   

    CCLayer::onExit();
}


void MotionStreakLayer::addSnowMtionStreak()
{
		
			CCParticleSnow *snow=CCParticleSnow::create();
			
			snow->setPosition(ccp(400,480));

			snow->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage("Images/snow.png"),CCRectMake(0,0,32,32));
			
			snow->setSpeed(20);

			ccColor4F rgba={1,1,1,1};
			

			snow->setStartColor(rgba);

			addChild(snow,1);


}

 void MotionStreakLayer::getLine(CCPoint pt)
 {
	 	CCParticleFireworks *fire=CCParticleFireworks::create();
		//fire->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage("Particle.png") ,CCRectMake(0,0,32,32));
		fire->setBlendAdditive(true);//这个调用必不可少
		fire->setDuration(10);
		fire->setLife(4);
		fire->setPosition(ccp(550,-5));
		fire->setScaleY(2);
		ccColor4F start={1,1,1,1};
		fire->setStartColor(start);

		CCParticleFireworks *fire2=CCParticleFireworks::create();
		//fire2->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage("Particle.png") ,CCRectMake(0,0,32,32));
		fire2->setBlendAdditive(true);//这个调用必不可少
		fire2->setDuration(10);
		fire->setLife(4);
		fire2->setPosition(ccp(250,-5));
		fire2->setScaleY(2);
		ccColor4F start2={1,1,1,1};
		fire2->setStartColor(start2);



		addChild(fire);
		fire->setAutoRemoveOnFinish(true);

		addChild(fire2);
		fire2->setAutoRemoveOnFinish(true);





		/*
		cocos2d::CCParticleSystemQuad *mSystem=CCParticleSystemQuad::create("Particle.plist");
		//mSystem->initWithFile("Particle.plist");//plist文件可以通过例子编辑器获得
		mSystem->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage("Particle.png")
        ,CCRectMake(0,0,32,32));//加载图片，第一个参数是纹理，第二个参数是选择图片上的位置
		 mSystem->setBlendAdditive(true);//这个调用必不可少
		mSystem->setPosition(pt);//设置位置
		mSystem->setDuration(0.3f);
		mSystem->setLife(0.5f);
		addChild(mSystem);
		//mSystem->release();
		//delete mSystem;
		//CC_SAFE_DELETE(mSystem);
		
		mSystem->setAutoRemoveOnFinish(true);
		*/
 }

  bool MotionStreakLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
 {
	 x=pTouch->getLocation().x;
	 y=pTouch->getLocation().y;
	 CCLog("ccTouchBegan");
	 return true;
 }
 void MotionStreakLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
 {
	 CCLog("ccTouchMoved");
	 getLine(pTouch->getLocation());
 }
 void MotionStreakLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
 {
	 if(fabs(pTouch->getLocation().x-x)<20&&fabs(pTouch->getLocation().y-y)<20)
	 {
		 getLine(pTouch->getLocation());
	 }
	 CCLog("ccTouchEnded");
 }
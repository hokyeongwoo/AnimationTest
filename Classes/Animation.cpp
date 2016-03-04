/*
	목표 : CCSprite에다가 Animation 동작을 주는것
*/

#include "cocos2d.h"
#include "Animation.h"
\
// Cococs2d-x의 namespace를 사용하게 되어있는 매크로
USING_NS_CC;

AnimationScene::AnimationScene()
{

}

AnimationScene::~AnimationScene()
{

}

bool AnimationScene::init()
{
	AnimationLayer* layer = AnimationLayer::create();
	this->addChild(layer);
	return true;
}

AnimationLayer::AnimationLayer()
{

}

AnimationLayer::~AnimationLayer()
{

}

bool AnimationLayer::init()
{
	// 기본적인 여러장의 이미지를 애니메이션화 하는 방법
	//AnimationSpriteView();

	// Animation 에서 SpriteFrame을 바로 추가하기.
	//AnimationAddforSpriteFrameView();

	// 하나의 이미지로 통합할 경우에 대한 방법
	//OneImageUserAnimationView();

	// 애니메이션에 textrue를 바로 추가하기.
	AnimationAddforTextureView();

	return true;
}

void AnimationLayer::AnimationSpriteView()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// 1. 애니메이션이 필요한 객체 생성
	CCSprite* sprite = CCSprite::create("grossini.png");
	sprite->setPosition(ccp(size.width / 2, size.height / 2));

	// CCSpriteFrame은 매 프레임마다 어떠한 이미지를 보여줄것인지에 대한 정보
	// 2. 순차적으로 재생할 CCSpriteFrame 객체 생성
	CCSpriteFrame* sprite_frame1 = CCSpriteFrame::create("grossini_dance_01.png", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame2 = CCSpriteFrame::create("grossini_dance_02.png", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame3 = CCSpriteFrame::create("grossini_dance_03.png", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame4 = CCSpriteFrame::create("grossini_dnace_04.png", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame5 = CCSpriteFrame::create("grossini_dance_05.png", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame6 = CCSpriteFrame::create("grossini_dance_06.png", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame7 = CCSpriteFrame::create("grossini_dance_07.png", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame8 = CCSpriteFrame::create("grossini_dance_08.png", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame9 = CCSpriteFrame::create("grossini_dance_09.png", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame10 = CCSpriteFrame::create("grossini_dance_10.png", CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame11 = CCSpriteFrame::create("grossini_dance_11.png", CCRect(0, 0, 85, 121));

	// CCAnimation에는 애니메이션 정보가 담겨있다.(어떤 간격으로 이미지가 전환되는지)
	// 3. CCSpriteFrame들을 저장할 목록으로 CCAnimation을 생성
	CCAnimation* animation = CCAnimation::create();
	animation->setDelayPerUnit(0.5f);
	animation->addSpriteFrame(sprite_frame1);
	animation->addSpriteFrame(sprite_frame2);
	animation->addSpriteFrame(sprite_frame3);
	animation->addSpriteFrame(sprite_frame4);
	animation->addSpriteFrame(sprite_frame5);
	animation->addSpriteFrame(sprite_frame6);
	animation->addSpriteFrame(sprite_frame7);
	animation->addSpriteFrame(sprite_frame8);
	animation->addSpriteFrame(sprite_frame9);
	animation->addSpriteFrame(sprite_frame10);
	animation->addSpriteFrame(sprite_frame11);

	// CCSprite에  runAction이라는 함수를 사용하여 특정 동작들을 수행
	// CCAnimate는 CCAnimation을 인자로 받아 해당 Animation(동작하고 멈추고, 시간에 따른 동작)을 Animate, 수행
	// 4. 처음 생성한 CCSprite에 CCAnimaion을 실행하도록 CCAnimate를 runAction 함
	sprite->runAction(CCAnimate::create(animation));

	this->addChild(sprite);
}

void AnimationLayer::AnimationAddforSpriteFrameView()
{
	// 여러장의 이미지 파일을 애니메이션으로 말들고자 할때 사용
	// CCAnimation에서는 addSpriteFrameWithFilename으로 말들 수 있다.
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	
	CCSprite *sprite = CCSprite::create("grossini.png");
	sprite->setPosition(ccp(size.width / 2, size.height / 2));

	CCAnimation * animation = CCAnimation::create();
	animation->setDelayPerUnit(0.5f);
	animation->addSpriteFrameWithFileName("grossini_dance_01.png");
	animation->addSpriteFrameWithFileName("grossini_dance_02.png");
	animation->addSpriteFrameWithFileName("grossini_dance_03.png");
	animation->addSpriteFrameWithFileName("grossini_dance_04.png");
	animation->addSpriteFrameWithFileName("grossini_dance_05.png");
	animation->addSpriteFrameWithFileName("grossini_dance_06.png");
	animation->addSpriteFrameWithFileName("grossini_dance_07.png");
	animation->addSpriteFrameWithFileName("grossini_dance_08.png");
	animation->addSpriteFrameWithFileName("grossini_dance_09.png");
	animation->addSpriteFrameWithFileName("grossini_dance_10.png");
	animation->addSpriteFrameWithFileName("grossini_dance_11.png");

	sprite->runAction(CCAnimate::create(animation));
	this->addChild(sprite);
}

void AnimationLayer::OneImageUserAnimationView()
{
	// 용량의 문제로 여러 이미지를 하나의 이미지로 합치는 경우 texture load를 한번만 하게하여 성능을 높인다.
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCSprite *sprite = CCSprite::create("grossini.png");
	sprite->setPosition(ccp(size.width / 2, size.height / 2));

	CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("grossini_dance_atlas.png");
	
	CCSpriteFrame* sprite_frame1 = CCSpriteFrame::createWithTexture(texture, CCRect(0, 0, 85, 121));
	CCSpriteFrame* sprite_frame2 = CCSpriteFrame::createWithTexture(texture, CCRect(85, 0, 85, 121));
	CCSpriteFrame* sprite_frame3 = CCSpriteFrame::createWithTexture(texture, CCRect(85*2, 0, 85, 121));
	CCSpriteFrame* sprite_frame4 = CCSpriteFrame::createWithTexture(texture, CCRect(85*3, 0, 85, 121));
	CCSpriteFrame* sprite_frame5 = CCSpriteFrame::createWithTexture(texture, CCRect(85*4, 0, 85, 121));

	CCAnimation* animation = CCAnimation::create();
	animation->setDelayPerUnit(0.5f);
	animation->addSpriteFrame(sprite_frame1);
	animation->addSpriteFrame(sprite_frame2);
	animation->addSpriteFrame(sprite_frame3);
	animation->addSpriteFrame(sprite_frame4);
	animation->addSpriteFrame(sprite_frame5);

	sprite->runAction(CCAnimate::create(animation));
	this->addChild(sprite);
}

void AnimationLayer::AnimationAddforTextureView()
{
	// 애니메이션에 texture 바로 추가하기
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCSprite *sprite = CCSprite::create("grossini.png");
	sprite->setPosition(ccp(size.width / 2, size.height / 2));

	CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("grossini_dance_atlas.png");

	CCAnimation * animation = CCAnimation::create();
	animation->setDelayPerUnit(0.5f);
	animation->addSpriteFrameWithTexture(texture, CCRect(0, 0, 85, 121));
	animation->addSpriteFrameWithTexture(texture, CCRect(85, 0, 85, 121));
	animation->addSpriteFrameWithTexture(texture, CCRect(85*2, 0, 85, 121));
	animation->addSpriteFrameWithTexture(texture, CCRect(85*3, 0, 85, 121));
	animation->addSpriteFrameWithTexture(texture, CCRect(85*4, 0, 85, 121));

	sprite->runAction(CCAnimate::create(animation));
	this->addChild(sprite);
}
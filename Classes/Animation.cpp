/*
	��ǥ : CCSprite���ٰ� Animation ������ �ִ°�
*/

#include "cocos2d.h"
#include "Animation.h"
\
// Cococs2d-x�� namespace�� ����ϰ� �Ǿ��ִ� ��ũ��
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
	// �⺻���� �������� �̹����� �ִϸ��̼�ȭ �ϴ� ���
	//AnimationSpriteView();

	// Animation ���� SpriteFrame�� �ٷ� �߰��ϱ�.
	//AnimationAddforSpriteFrameView();

	// �ϳ��� �̹����� ������ ��쿡 ���� ���
	//OneImageUserAnimationView();

	// �ִϸ��̼ǿ� textrue�� �ٷ� �߰��ϱ�.
	AnimationAddforTextureView();

	return true;
}

void AnimationLayer::AnimationSpriteView()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// 1. �ִϸ��̼��� �ʿ��� ��ü ����
	CCSprite* sprite = CCSprite::create("grossini.png");
	sprite->setPosition(ccp(size.width / 2, size.height / 2));

	// CCSpriteFrame�� �� �����Ӹ��� ��� �̹����� �����ٰ������� ���� ����
	// 2. ���������� ����� CCSpriteFrame ��ü ����
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

	// CCAnimation���� �ִϸ��̼� ������ ����ִ�.(� �������� �̹����� ��ȯ�Ǵ���)
	// 3. CCSpriteFrame���� ������ ������� CCAnimation�� ����
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

	// CCSprite��  runAction�̶�� �Լ��� ����Ͽ� Ư�� ���۵��� ����
	// CCAnimate�� CCAnimation�� ���ڷ� �޾� �ش� Animation(�����ϰ� ���߰�, �ð��� ���� ����)�� Animate, ����
	// 4. ó�� ������ CCSprite�� CCAnimaion�� �����ϵ��� CCAnimate�� runAction ��
	sprite->runAction(CCAnimate::create(animation));

	this->addChild(sprite);
}

void AnimationLayer::AnimationAddforSpriteFrameView()
{
	// �������� �̹��� ������ �ִϸ��̼����� ������� �Ҷ� ���
	// CCAnimation������ addSpriteFrameWithFilename���� ���� �� �ִ�.
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
	// �뷮�� ������ ���� �̹����� �ϳ��� �̹����� ��ġ�� ��� texture load�� �ѹ��� �ϰ��Ͽ� ������ ���δ�.
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
	// �ִϸ��̼ǿ� texture �ٷ� �߰��ϱ�
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
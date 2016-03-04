#pragma once

#include "cocos2d.h"

class AnimationScene : public cocos2d::CCScene
{
public:
	AnimationScene();
	virtual ~AnimationScene();
	virtual bool init();

	CREATE_FUNC(AnimationScene);
};

class AnimationLayer : public cocos2d::CCLayer
{
public:
	AnimationLayer();
	virtual ~AnimationLayer();
	virtual bool init();

	void AnimationSpriteView();
	void AnimationAddforSpriteFrameView();
	void OneImageUserAnimationView();
	void AnimationAddforTextureView();

	CREATE_FUNC(AnimationLayer);
};
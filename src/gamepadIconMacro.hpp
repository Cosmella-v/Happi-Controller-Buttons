#include "gamepadIcon.hpp"
#define gamepadIcon_replaceidless(node, oldnode, newframe, e)  \
if (node) { \
	auto gamepadicon = gamepadIconNodeGroup::create(); \
	auto placeholder = CCSprite::createWithSpriteFrameName(newframe); \
	gamepadicon->setID("my-cool-gyro"_spr); \
	gamepadicon->setContentSize({76, 14}); \
	gamepadicon->setAnchorPoint({0.5,0.5}); \
	gamepadicon->setLayout(SimpleRowLayout::create()->setMainAxisScaling(AxisScaling::ScaleDown)); \
	node->addChild(gamepadicon); \
	gamepadicon->addChild(placeholder); \
	gamepadicon->updateLayout(); \
    e; \
    if (oldnode) oldnode->setVisible(false); \
}
#define gamepadIcon_replace(snode, oldnode, newframe, id, e)  \
if (auto node = snode) { \
	auto gamepadicon = gamepadIconNodeGroup::create(); \
	auto placeholder = CCSprite::createWithSpriteFrameName(newframe); \
	gamepadicon->setContentSize({76, 14}); \
	gamepadicon->setAnchorPoint({0.5,0.5}); \
	gamepadicon->setLayout(SimpleRowLayout::create()->setMainAxisScaling(AxisScaling::ScaleDown)); \
	gamepadicon->setID(id); \
	node->addChild(gamepadicon); \
	gamepadicon->addChild(placeholder); \
	gamepadicon->updateLayout(); \
    e; \
    if (oldnode) oldnode->setVisible(false); \
}  
#define LockToCenter(offset) gamepadicon->setPosition(ccp(node->getContentSize().width / 2,-offset));

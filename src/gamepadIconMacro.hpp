#include "gamepadIcon.hpp"
#define gamepadIcon_replaceidless(node, oldnode, newframe, e)  \
if (node) { \
	auto gamepadicon = gamepadIconSprite::createWithSpriteFrameName(newframe); \
	gamepadicon->setID("my-cool-gyro"_spr); \
	node->addChild(gamepadicon); \
    e; \
    if (oldnode) oldnode->setVisible(false); \
}
#define gamepadIcon_replace(snode, oldnode, newframe, id, e)  \
if (auto node = snode) { \
	auto gamepadicon = gamepadIconSprite::createWithSpriteFrameName(newframe); \
	gamepadicon->setID(id); \
	node->addChild(gamepadicon); \
    e; \
    if (oldnode) oldnode->setVisible(false); \
}  
#define LockToCenter(offset) gamepadicon->setPosition(ccp(node->getContentSize().width / 2,-offset));

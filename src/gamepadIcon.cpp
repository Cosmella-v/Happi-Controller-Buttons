// someone will kill me for changing draw and hooking visit
#include "gamepadIcon.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/CCSprite.hpp>
#include "SingletonCache.hpp"
using namespace geode::prelude;
#define Drawer(Old) \
    CCNode* p = m_pParent; \
    if (!p) \
    { \
        return Old; \
    } \
    \
    CCSize size = m_obContentSize;\
    float fScaleXB = m_fScaleX; \
    float fScaleYB = m_fScaleY; \
    if (auto ccsp = typeinfo_cast<CCMenuItemSpriteExtra*>(p)) { \
        fScaleXB *= ccsp->m_baseScale; \
        fScaleYB *= ccsp->m_baseScale; \
    }; \
    float sx = p->getScaleX(); \
    float sy = p->getScaleY(); \
    float centerX = size.width * 0.5f; \
    float centerY = size.height; \
    kmGLTranslatef(centerX, centerY, 0); \
    if (sx != 0 && sy != 0){ \
        kmGLScalef(fScaleXB / sx, fScaleYB / sy, 1.0f); \
    } \
    kmGLTranslatef(-centerX, -centerY, 0); \
    return Old; \


void gamepadIconSprite::draw()
{
    Drawer(CCSprite::draw());
}
void gamepadIconSprite::visit()
{
    if (auto h = fast::get<cocos2d::CCApplication>()){ 
        if (!h->m_bControllerConnected) return;
    } else {return;}
    CCSprite::visit();
};

void gamepadIconNodeGroup::draw() {
    Drawer(CCNode::draw());
};
void gamepadIconNodeGroup::visit()
{
    if (auto h = fast::get<cocos2d::CCApplication>()){ 
        if (!h->m_bControllerConnected) return;
    } else {return;}
    CCNode::visit();
};
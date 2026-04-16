
#include <Geode/Geode.hpp>
#include <Geode/modify/CCSprite.hpp>
#include <Geode/modify/CCNode.hpp>
using namespace geode::prelude;
class gamepadIconSprite : public CCSprite {
public:
static gamepadIconSprite* createWithTexture(CCTexture2D *pTexture)
{
    gamepadIconSprite *pobSprite = new gamepadIconSprite();
    if (pobSprite && pobSprite->initWithTexture(pTexture))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

static gamepadIconSprite* createWithTexture(CCTexture2D *pTexture, const CCRect& rect)
{
    gamepadIconSprite *pobSprite = new gamepadIconSprite();
    if (pobSprite && pobSprite->initWithTexture(pTexture, rect))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

static gamepadIconSprite* create(const char *pszFileName)
{
    gamepadIconSprite *pobSprite = new gamepadIconSprite();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

static gamepadIconSprite* create(const char *pszFileName, const CCRect& rect)
{
    gamepadIconSprite *pobSprite = new gamepadIconSprite();
    if (pobSprite && pobSprite->initWithFile(pszFileName, rect))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

static gamepadIconSprite* createWithSpriteFrame(CCSpriteFrame *pSpriteFrame)
{
    gamepadIconSprite *pobSprite = new gamepadIconSprite();
    if (pSpriteFrame && pobSprite && pobSprite->initWithSpriteFrame(pSpriteFrame))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

static gamepadIconSprite* createWithSpriteFrameName(const char *pszSpriteFrameName)
{
    return gamepadIconSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(pszSpriteFrameName));
}

static gamepadIconSprite* create()
{
    gamepadIconSprite *pSprite = new gamepadIconSprite();
    if (pSprite && pSprite->init())
    {
        pSprite->autorelease();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}
protected:
    void draw() override;
    void visit() override;
};

class gamepadIconNodeGroup : public CCNode {
public:
static gamepadIconNodeGroup* create()
{
    gamepadIconNodeGroup *pnode = new gamepadIconNodeGroup();
    if (pnode && pnode->init())
    {
        pnode->autorelease();
        return pnode;
    }
    CC_SAFE_DELETE(pnode);
    return NULL;
}
protected:
    void draw() override;
    void visit() override;
};
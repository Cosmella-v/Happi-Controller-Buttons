#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
using namespace geode::prelude;

class $modify(Button2LevelBrowserLayer, LevelBrowserLayer) {
	bool init(GJSearchObject* search) {
        if (!LevelBrowserLayer::init(search)) return false;
        /* 
        500, 262 -> controller-scroll-up
        -- > 22
        500, 240 -> controller-scroll-rthumb
        -- > 22
        500, 218 -> controller-scroll-down
        */
        CCNode* up = this->getChildByIDRecursive("controller-scroll-up");
        CCNode* rthumb = this->getChildByIDRecursive("controller-scroll-rthumb");
        CCNode* down = this->getChildByIDRecursive("controller-scroll-down");
        if (down && up && rthumb) {
            auto winSize = CCDirector::get()->getWinSize();
			auto pos = winSize.height / 2 + 30;
			auto posx = winSize.width / 2 + 205.f;
                rthumb->setPosition({
                    posx, pos
                });
                down->setPosition({
                    posx, pos - 22
                });
                up->setPosition({
                    posx, pos + 22
                });
        }
        return true;
    }
};
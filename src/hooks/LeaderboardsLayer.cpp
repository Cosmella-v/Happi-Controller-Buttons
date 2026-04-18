#include <Geode/Geode.hpp>
#include <Geode/modify/LeaderboardsLayer.hpp>
#include "../SingletonCache.hpp"
using namespace geode::prelude;
bool g_toggle = false;
$on_mod(Loaded) {
	g_toggle = geode::Mod::get()->getSettingValue<bool>("force-icons");
	geode::listenForSettingChanges<bool>("force-icons", [](bool toggled){
        g_toggle = toggled;
    });
}

class $modify(Button2LeaderboardsLayer, LeaderboardsLayer) {
	bool init(LeaderboardType type, LeaderboardStat Stat) {
		if (!LeaderboardsLayer::init(type, Stat))
			return false;
		if (!g_toggle) {
			#ifdef GEODE_IS_WINDOWS
			if (auto h = fast::get<cocos2d::CCApplication>()){ 
				if (!h->m_bControllerConnected) return true;
			} else {return true;}
			#else
				if (!PlatformToolbox::isControllerConnected()) return true;
			#endif
		}
		GameToolbox::addRThumbScrollButton(this);
		CCNode *up = this->getChildByIDRecursive("controller-scroll-up");
		CCNode *rthumb = this->getChildByIDRecursive("controller-scroll-rthumb");
		CCNode *down = this->getChildByIDRecursive("controller-scroll-down");
		if (down && up && rthumb) {
			auto winSize = CCDirector::get()->getWinSize();
			auto pos = winSize.height / 2 + 20;
			auto posx = winSize.width / 2 + 205.f;
			rthumb->setPosition({posx, pos});
			down->setPosition({posx, pos - 22});
			up->setPosition({posx, pos + 22});
			if (auto right = this->getChildByIDRecursive("right-side-menu")) {
				right->setPositionX(posx + 25);
			};
		}
		return true;
	}
};
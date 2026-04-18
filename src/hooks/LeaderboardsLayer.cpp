#include <Geode/Geode.hpp>
#include <Geode/modify/LeaderboardsLayer.hpp>
using namespace geode::prelude;

class $modify(Button2LeaderboardsLayer, LeaderboardsLayer) {
	bool init(LeaderboardType type, LeaderboardStat Stat) {
		if (!LeaderboardsLayer::init(type, Stat))
			return false;
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
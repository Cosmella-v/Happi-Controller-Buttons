#include <Geode/Geode.hpp>
#include "../../include/gamepad.hpp"
#include <Geode/modify/LevelInfoLayer.hpp>
using namespace geode::prelude;

class $modify(Button2LevelInfoLayer, LevelInfoLayer) {
	bool init(GJGameLevel* level, bool challenge) {
		if (!LevelInfoLayer::init(level, challenge)) {
			return false;
		}
        if (auto btn = typeinfo_cast<CCMenuItemSpriteExtra*>(this->getChildByIDRecursive("play-button"))) {
            CCNode* gamepadIcon = nullptr;
            if (PlatformToolbox::isControllerConnected()) {
                if (auto img = btn->getNormalImage()) { // idless gamepad icon
                    if (auto fix = img->getChildByType<CCSprite*>(0))   gamepadIcon = fix;
                }
            }
            cosmella::HappiControllerButtons::Macros::Center(
                cosmella::HappiControllerButtons::AddControllerIcon(
                    btn,
                    gamepadIcon,
                    geode::Keybind(cocos2d::CONTROLLER_Start, geode::KeyboardModifier::None),
                    "play-icon"_spr
                ),
                -8
            );
        }
		
		return true;
	}
};
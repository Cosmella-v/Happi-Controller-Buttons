#include <Geode/Geode.hpp>
#include "../../include/gamepad.hpp"
#include <Geode/modify/EditLevelLayer.hpp>
using namespace geode::prelude;

class $modify(Button2EditLevelLayer, EditLevelLayer) {
	bool init(GJGameLevel* level) {
		if (!EditLevelLayer::init(level)) {
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
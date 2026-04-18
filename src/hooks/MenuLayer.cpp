#include <Geode/Geode.hpp>
#include "../../include/gamepad.hpp"
#include <Geode/modify/MenuLayer.hpp>
using namespace geode::prelude;

class $modify(Button2MenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		cosmella::HappiControllerButtons::Macros::Center(
			cosmella::HappiControllerButtons::AddControllerIcon(
				this->getChildByIDRecursive("play-button"),
				this->getChildByIDRecursive("play-gamepad-icon"),
				geode::Keybind(cocos2d::CONTROLLER_Start, geode::KeyboardModifier::None),
				"play-icon"_spr
			),
			10
		);
		cosmella::HappiControllerButtons::Macros::Center(
			cosmella::HappiControllerButtons::AddControllerIcon(
				this->getChildByIDRecursive("icon-kit-button"),
				this->getChildByIDRecursive("icon-kit-gamepad-icon"),
				geode::Keybind(cocos2d::CONTROLLER_X, geode::KeyboardModifier::None),
				"icon-kit-icon"_spr
			),
			10
		);
		cosmella::HappiControllerButtons::Macros::Center(
			cosmella::HappiControllerButtons::AddControllerIcon(
				this->getChildByIDRecursive("editor-button"),
				this->getChildByIDRecursive("editor-gamepad-icon"),
				geode::Keybind(cocos2d::CONTROLLER_Y, geode::KeyboardModifier::None),
				"editor-icon"_spr
			),
			10
		);
		cosmella::HappiControllerButtons::Macros::Center(
			cosmella::HappiControllerButtons::AddControllerIcon(
				this->getChildByIDRecursive("settings-button"),
				this->getChildByIDRecursive("settings-gamepad-icon"),
				geode::Keybind(cocos2d::CONTROLLER_Down, geode::KeyboardModifier::None),
				"settings-icon"_spr
			),
			10
		);
		
		return true;
	}
};
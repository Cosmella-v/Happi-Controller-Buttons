#include "../../include/gamepad.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
using namespace geode::prelude;

class $modify(Button2EndLevelLayer, EndLevelLayer) {
	void customSetup() override {
		EndLevelLayer::customSetup();
		cosmella::HappiControllerButtons::Macros::Center(
		    cosmella::HappiControllerButtons::AddControllerIcon(
		        this->getChildByIDRecursive("retry-button"),
		        this->getChildByIDRecursive("controller-retry-hint"),
		        geode::Keybind(cocos2d::CONTROLLER_Start, geode::KeyboardModifier::None),
		        "retry-icon"_spr),
		    -8);
		cosmella::HappiControllerButtons::Macros::Center(
		    cosmella::HappiControllerButtons::AddControllerIcon(
		        this->getChildByIDRecursive("exit-button"),
		        this->getChildByIDRecursive("controller-exit-hint"),
		        geode::Keybind(cocos2d::CONTROLLER_B, geode::KeyboardModifier::None),
		        "exit-icon"_spr),
		    -8);
	};
};
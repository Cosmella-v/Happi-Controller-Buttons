#include <Geode/Geode.hpp>
#include "gamepadIconMacro.hpp"
#include <Geode/modify/MenuLayer.hpp>
using namespace geode::prelude;

class $modify(Gyro2MenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		
		gamepadIcon_replace(
			this->getChildByIDRecursive("play-button"),
			this->getChildByIDRecursive("play-gamepad-icon"),
			"controllerBtn_Start_001.png",
			"play-icon"_spr,
			LockToCenter(10)
		)
		gamepadIcon_replace(
			this->getChildByIDRecursive("icon-kit-button"),
			this->getChildByIDRecursive("icon-kit-gamepad-icon"),
			"controllerBtn_X_001.png",
			"icon-kit-icon"_spr,
			LockToCenter(10) gamepadicon->setScale(0.8);
		)
		gamepadIcon_replace(
			this->getChildByIDRecursive("editor-button"),
			this->getChildByIDRecursive("editor-gamepad-icon"),
			"controllerBtn_Y_001.png",
			"editor-icon"_spr,
			LockToCenter(10) gamepadicon->setScale(0.8);
		)
		gamepadIcon_replace(
			this->getChildByIDRecursive("settings-button"),
			this->getChildByIDRecursive("settings-gamepad-icon"),
			"controllerBtn_DPad_Down_001.png",
			"settings-icon"_spr,
			LockToCenter(10) gamepadicon->setScale(0.8);
		)
		
		return true;
	}
};
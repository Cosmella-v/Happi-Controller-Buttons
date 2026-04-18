#include "../../include/gamepad.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
using namespace geode::prelude;

class $modify(Button2PauseLayer, PauseLayer) {
	void customSetup() override {
		PauseLayer::customSetup();
		auto ckb = Loader::get()->getInstalledMod("geode.custom-keybinds");
		cosmella::HappiControllerButtons::Macros::Center(
		    cosmella::HappiControllerButtons::AddControllerIcon(
		        this->getChildByIDRecursive("play-button"),
		        this->getChildByIDRecursive("controller-play-hint"),
		        geode::Keybind(cocos2d::CONTROLLER_Start, geode::KeyboardModifier::None),
		        "play-icon"_spr,
		        "unpause-level",
		        ckb),
		    0);
		cosmella::HappiControllerButtons::Macros::Center(
		    cosmella::HappiControllerButtons::AddControllerIcon(
		        this->getChildByIDRecursive("exit-button"),
		        this->getChildByIDRecursive("controller-back-hint"),
		        geode::Keybind(cocos2d::CONTROLLER_B, geode::KeyboardModifier::None),
		        "exit-button"_spr,
		        "exit-level",
		        ckb),
		    0);
		cosmella::HappiControllerButtons::Macros::Center(
		    cosmella::HappiControllerButtons::AddControllerIcon(
		        this->getChildByIDRecursive("practice-button"),
		        this->getChildByIDRecursive("controller-practice-hint"),
		        geode::Keybind(cocos2d::CONTROLLER_X, geode::KeyboardModifier::None),
		        "practice-button"_spr,
		        "practice-level",
		        ckb),
		    0);
	};
};
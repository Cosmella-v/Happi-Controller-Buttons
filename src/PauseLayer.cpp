#include <Geode/Geode.hpp>
#include "gamepadIconMacro.hpp"
#include <Geode/modify/PauseLayer.hpp>
using namespace geode::prelude;

class $modify(Gyro2PauseLayer, PauseLayer) {
    void customSetup() override {
        PauseLayer::customSetup();
        gamepadIcon_replace(
            this->getChildByIDRecursive("play-button"),
            this->getChildByIDRecursive("controller-play-hint"),
            "controllerBtn_Start_001.png",
            "play-icon"_spr,
            LockToCenter(0); gamepadicon->setScale(0.8)
        )
        gamepadIcon_replace(
            this->getChildByIDRecursive("exit-button"),
            this->getChildByIDRecursive("controller-back-hint"),
            "controllerBtn_B_001.png",
            "icon-kit-icon"_spr,
            LockToCenter(0) gamepadicon->setScale(0.8);
        )
        gamepadIcon_replace(
            this->getChildByIDRecursive("practice-button"),
            this->getChildByIDRecursive("controller-practice-hint"),
            "controllerBtn_X_001.png",
            "editor-icon"_spr,
            LockToCenter(0) gamepadicon->setScale(0.8);
        )
    };
};
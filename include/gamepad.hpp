#pragma once

#include <Geode/loader/Dispatch.hpp>
#include <Geode/loader/Loader.hpp>
#include <Geode/utils/VersionInfo.hpp>

#include <filesystem>
#include <vector>
#include <string>

#ifdef MY_MOD_ID
    #undef MY_MOD_ID
#endif
#define MY_MOD_ID "cosmella.controllerbuttons-2"

namespace cosmella::HappiControllerButtons {

inline bool isLoaded() {
    return geode::Loader::get()->isModLoaded(MY_MOD_ID);
}

namespace Macros {
    inline cocos2d::CCNode* Center(
        cocos2d::CCNode* gamepadicon,
        float offset
    ) {
        if (auto parent = gamepadicon->getParent()) {
            gamepadicon->setPosition(ccp(parent->getContentSize().width / 2,-offset));
        };
        return gamepadicon;
    };
}

inline cocos2d::CCNode* AddControllerIcon(
    cocos2d::CCNode* PNode, 
    cocos2d::CCNode* hint = nullptr,
    geode::Keybind defaultKey = geode::Keybind(cocos2d::CONTROLLER_Start, geode::KeyboardModifier::None), 
    const char* id ="unknown-icon"_spr,
    const char* setting = nullptr,
    geode::Mod* mod=nullptr,
    cocos2d::CCMenuItem* item= nullptr
) GEODE_EVENT_EXPORT_NORES(&AddControllerIcon, (
    PNode,
    hint,
    defaultKey,
    id,
    setting,
    mod,
    item
));

inline cocos2d::CCNode* AddControllerIconWithModID(
    cocos2d::CCNode* PNode, 
    cocos2d::CCNode* hint = nullptr,
    geode::Keybind defaultKey = geode::Keybind(cocos2d::CONTROLLER_Start, geode::KeyboardModifier::None), 
    const char* id ="unknown-icon"_spr,
    const char* setting = nullptr,
    const char* modid = MY_MOD_ID,
    cocos2d::CCMenuItem* item= nullptr
) {
return AddControllerIcon(
    PNode,
    hint,
    defaultKey,
    id,
    setting,
    geode::Loader::get()->getInstalledMod(modid),
    item);
};

}

#undef MY_MOD_ID
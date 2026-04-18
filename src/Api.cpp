#define GEODE_DEFINE_EVENT_EXPORTS
#include "../include/gamepad.hpp"
#include "gamepadIconMacro.hpp"

using namespace geode;
namespace api = cosmella::HappiControllerButtons;

CCNode* api::AddControllerIcon(
    CCNode* PNode, 
    CCNode* hint,
    Keybind defaultKey, 
    const char* id,
    const char* setting,
    Mod * mod,
    CCMenuItem* item
) {
    if (auto node = PNode) { 
        if (auto self = PNode->getChildByType<gamepadIconNodeGroup>(0)) {
            self->DefaultIcon(defaultKey);
            if (setting != nullptr && mod != nullptr) {
                if (item != nullptr) {
                    self->LinkTo(setting,mod, item);
                } else {
                    self->LinkTo(setting,mod);
                }
            };
            return self;
        }
        auto gamepadicon = gamepadIconNodeGroup::create(); 
        gamepadicon->setContentSize({76, 14}); 
        gamepadicon->setAnchorPoint({0.5,0.5}); 
        gamepadicon->setLayout(SimpleRowLayout::create()->setMainAxisScaling(AxisScaling::ScaleDown));
        gamepadicon->setID(id); 
        node->addChild(gamepadicon); 
        gamepadicon->DefaultIcon(defaultKey);
        gamepadicon->updateLayout(); 
        gamepadicon->setScale(0.8); // most of them are scale 0.8 anyways
        if (setting != nullptr && mod != nullptr) {
            if (item != nullptr) {
                gamepadicon->LinkTo(setting,mod, item);
            } else {
                gamepadicon->LinkTo(setting,mod);
            }
        };
        if (hint) hint->setVisible(false); 
        return gamepadicon;
    }
    return nullptr;
}
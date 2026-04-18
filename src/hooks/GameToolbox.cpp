#include "../../include/gamepad.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/GameToolbox.hpp>
using namespace geode::prelude;

class $modify(Button2GayToolbox, GameToolbox) {
	static void addBackButton(CCLayer *layer, CCMenuItem *item) {
		GameToolbox::addBackButton(layer, item);
		auto gamepadicon = cosmella::HappiControllerButtons::AddControllerIcon(
		    item,
		    layer->getChildByIDRecursive("controller-back-hint"),
		    geode::Keybind(cocos2d::CONTROLLER_B, geode::KeyboardModifier::None),
		    "exit-icon"_spr);
		if (gamepadicon) {
			if (auto parent = gamepadicon->getParent()) {
				auto size = parent->getContentSize();
				gamepadicon->setPosition(ccp(size.width + 8.5, size.height / 2));
				gamepadicon->setContentSize({14, 76});
                gamepadicon->setLayout(SimpleColumnLayout::create()->setMainAxisScaling(AxisScaling::ScaleDown));
			};
		}
	}
};

#include <Geode/Geode.hpp>
#include <Geode/modify/CCNode.hpp>
#include <Geode/modify/CCSprite.hpp>
using namespace geode::prelude;

// from custom keybinds
static void addBindSprites(CCNodeRGBA *target, const char *action, Mod *mod) {
	if (target == nullptr)
		return;
	if (mod == nullptr)
		return;
	target->removeAllChildren();
	bool first = true;
	for (auto &bind : mod->getSettingValue<std::vector<Keybind>>(action)) {
		if (!first) {
			auto separator = CCLabelBMFont::create("/", "goldFont.fnt");
			separator->setScale(.8f);
			separator->setOpacity(target->getOpacity());
			target->addChild(separator);
		}
		first = false;
		auto label = bind.createNode();
		if (auto text = typeinfo_cast<CCLabelBMFont *>(label)) {
			text->setFntFile("bigFont.fnt");
		}
		label->setScale(.8f);
		if (auto rgba = typeinfo_cast<CCRGBAProtocol *>(label)) {
			rgba->setOpacity(target->getOpacity());
		}
		target->addChild(label);
	};
    target->updateLayout(); 
}

class gamepadIconNodeGroup : public CCNodeRGBA {
  public:
	static gamepadIconNodeGroup *create() {
		gamepadIconNodeGroup *pnode = new gamepadIconNodeGroup();
		if (pnode && pnode->init()) {
			pnode->autorelease();
			return pnode;
		}
		CC_SAFE_DELETE(pnode);
		return NULL;
	};
	void DefaultIcon(Keybind defaultKey){
		if (m_setting && m_mod) return addBindSprites(this, m_setting, m_mod);
		if (CCNode* Node = defaultKey.createNode()) {
			this->removeAllChildren();
			this->addChild(Node); 
			this->updateLayout(); 
		}
	}
	void LinkTo(const char *setting, Mod *mod) {
        if (Warn()) {
            geode::log::error("Node has already been registered with setting\nthis may break mods please report this!");
            return;
        };
		m_setting = setting;
		m_mod = mod;
		addBindSprites(this, m_setting, m_mod);
        this->addEventListener(SettingChangedEventV3(mod, m_setting),
        [this](auto h){
            addBindSprites(this, m_setting, m_mod);
        });
	};
	void LinkTo(const char *setting, Mod *mod, CCMenuItem *item) {
        if (Warn()) {
            geode::log::error("Node has already been registered with callback\nthis may break mods please report this!");
            return;
        };
		m_setting = setting;
		m_mod = mod;
		addBindSprites(this, m_setting, m_mod);
        this->addEventListener(SettingChangedEventV3(mod, m_setting),
            [this](auto h){
                addBindSprites(this, m_setting, m_mod);
            });
		m_listener = this->addEventListener(
		    KeybindSettingPressedEventV3(m_mod, m_setting),
		    [item = WeakRef<CCMenuItem>(item)](Keybind const &keybind, bool down, bool repeat, double timestamp) {
			    if (repeat || !down) {
				    return ListenerResult::Propagate;
			    }
                if (auto c = item.lock()) c->activate();

			    return ListenerResult::Stop;
		    });
	};

  protected:
	const char *m_setting;
	Mod *m_mod;
	CCMenuItem *m_item;
    ListenerHandle* m_listener;
    bool Warn() {
        return m_listener != nullptr || m_mod != nullptr || m_setting != nullptr;
    };
	void draw() override;
	void visit() override;
};
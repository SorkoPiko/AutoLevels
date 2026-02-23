#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/web.hpp>
#include "../managers/AutoLevels.hpp"

using namespace geode::prelude;

class $modify(ALMenuLayer, MenuLayer) {

    struct Fields {
        TaskHolder<web::WebResponse> m_listener;
    };

    bool init() {
        if (!MenuLayer::init()) return false;

        m_fields->m_listener.spawn(
            web::WebRequest().get("https://gist.githubusercontent.com/SorkoPiko/e34dc27750493641b75b92ce5bda2ebc/raw/autoLevels.json"),
            [] (const web::WebResponse& e) {
                if (!e.ok()) {
                    log::warn("Request Failed");
                    return;
                }

                AutoLevels::setLevels(e.json().unwrapOrDefault().as<std::vector<int>>().unwrapOrDefault());
        });

        return true;
    }
};
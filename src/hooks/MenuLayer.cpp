#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/web.hpp>
#include "../managers/AutoLevels.hpp"

using namespace geode::prelude;

class $modify(ALMenuLayer, MenuLayer) {

    struct Fields {
        EventListener<web::WebTask> m_listener;
    };

    bool init() {
        if (!MenuLayer::init()) return false;

        m_fields->m_listener.bind([] (web::WebTask::Event* e) {
            if (const auto res = e->getValue()) {
                if (!res->ok()) {
                    log::warn("Request Failed");
                    return;
                }

                AutoLevels::setLevels(res->json().unwrapOrDefault().as<std::vector<int>>().unwrapOrDefault());
            } else if (e->isCancelled()) {
                log::warn("Request Cancelled");
            }
        });

        auto req = web::WebRequest();
        m_fields->m_listener.setFilter(req.get("https://secretway.sorkopiko.com/api/auto"));

        return true;
    }
};
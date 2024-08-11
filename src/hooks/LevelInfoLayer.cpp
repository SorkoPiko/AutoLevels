#include <Geode/modify/LevelInfoLayer.hpp>
#include "../managers/AutoLevels.hpp"

using namespace geode::prelude;

class $modify(ALLevelInfoLayer, LevelInfoLayer) {
    bool init(GJGameLevel *level, const bool challenge) {
        if (!LevelInfoLayer::init(level, challenge)) return false;

        drawSprite();
        return true;
    }

    void levelDownloadFinished(GJGameLevel *level) {
        LevelInfoLayer::levelDownloadFinished(level);
        drawSprite();
    }

    void drawSprite() const {
        const auto difficultySprite = m_difficultySprite;
        if (!m_level) return;
        if (!difficultySprite) return;
        if (AutoLevels::checkLevel(m_level->m_levelID.value())) {
            difficultySprite->updateDifficultyFrame(-1, GJDifficultyName::Long);
        }
    }
};
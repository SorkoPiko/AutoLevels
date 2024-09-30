#include <Geode/modify/LevelCell.hpp>
#include "../managers/AutoLevels.hpp"

using namespace geode::prelude;

class $modify(ALLevelCell, LevelCell) {
    void loadCustomLevelCell() {
        LevelCell::loadCustomLevelCell();

        if (!m_level) return;
        auto difficultyContainer= m_mainLayer->getChildByID("difficulty-container");
        if (!difficultyContainer) {
            difficultyContainer = m_mainLayer->getChildByID("grd-demon-icon-layer");
        }
        if (!difficultyContainer) return;
        const auto difficultySpriteRaw = difficultyContainer->getChildByID("difficulty-sprite");
        if (!difficultySpriteRaw) return;
        const auto difficultySprite = static_cast<GJDifficultySprite*>(difficultySpriteRaw);

        if (AutoLevels::checkLevel(m_level->m_levelID.value())) {
            difficultySprite->updateDifficultyFrame(-1, GJDifficultyName::Short);
        }
    }
};
#include <Geode/modify/LevelCell.hpp>
#include "../managers/AutoLevels.hpp"

using namespace geode::prelude;

class $modify(ALLevelCell, LevelCell) {
    void loadCustomLevelCell() {
        LevelCell::loadCustomLevelCell();

        if (!m_level) return;
        log::info("levelcell");
        const auto difficultySpriteRaw = m_mainLayer->getChildByID("difficulty-container")->getChildByID("difficulty-sprite");
        if (!difficultySpriteRaw) return;
        const auto difficultySprite = static_cast<GJDifficultySprite*>(difficultySpriteRaw);

        if (AutoLevels::checkLevel(m_level->m_levelID.value())) {
            difficultySprite->updateDifficultyFrame(-1, GJDifficultyName::Short);
        }
    }
};
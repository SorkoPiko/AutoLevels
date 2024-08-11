#include "AutoLevels.hpp"

using namespace geode::prelude;

std::vector<int> AutoLevels::levels = {};

bool AutoLevels::checkLevel(const int levelID) {
    return std::find(levels.begin(), levels.end(), levelID) != levels.end();
}

void AutoLevels::setLevels(const std::vector<int> &newLevels) {
    if (!levels.empty()) return;
    levels = newLevels;
}
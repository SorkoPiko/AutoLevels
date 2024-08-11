#ifndef AUTOLEVELS_HPP
#define AUTOLEVELS_HPP

using namespace geode::prelude;

class AutoLevels {
protected:
    static std::vector<int> levels;

public:
    static bool checkLevel(int levelID);
    static void setLevels(const std::vector<int> &newLevels);

};

#endif

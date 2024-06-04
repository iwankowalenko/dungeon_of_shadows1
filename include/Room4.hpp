#pragma once

#include "Hero.hpp"
#include "Riddles.hpp"
#include <unordered_map>

class Room4 {
public:
    void initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited);

private:
    void presentRiddle(Hero& hero);
};

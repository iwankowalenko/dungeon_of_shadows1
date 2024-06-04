#pragma once

#include "../include/Hero.hpp"
#include "../include/HeroFileFunction.hpp"
#include "../include/Prologue.hpp"
#include "../include/Room1.hpp"

#include <string>
#include <iostream>
#include <unordered_map>

class StartMenu {
public:
    StartMenu() = default;
    StartMenu(const StartMenu& other) = delete;

    void initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited);

private:
    enum COMMAND {
        EXIT,
        START_CONTINUE,
        START_NEW_GAME
    };

    static std::string m_lower(std::string str);
    static void m_Separation();
};

#include "../include/Riddles.hpp"
#include "../include/Hero.hpp"
#include <algorithm>
#include <iostream>
#include <Windows.h>

std::string& Riddles::m_lower(std::string& Line) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::transform(Line.begin(), Line.end(), Line.begin(), ::tolower);
    return Line;
}

void RiddleBed::printRiddle() const {

    std::cout << m_Riddle << std::endl;
}

bool RiddleBed::isTrue(std::string& UserAnswer, Hero& hero) const {

    m_lower(UserAnswer);
    if (UserAnswer == m_answer) {
        hero.SetEXP(hero.GetEXP() + 100);
        hero.SetHP(hero.GetMaxHP());
        return true;
    }
    return false;
}

void RiddleBook::printRiddle() const {

    std::cout << m_Riddle << std::endl;
}

bool RiddleBook::isTrue(std::string& UserAnswer, Hero& hero) const {

    m_lower(UserAnswer);
    if (UserAnswer == m_answer) {
        hero.SetEXP(hero.GetEXP() + 100);
        hero.SetHP(hero.GetMaxHP());
        return true;
    }
    return false;
}

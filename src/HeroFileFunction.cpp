#include "..\include\HeroFileFunction.hpp"

#include <fstream>
#include <iostream>

void saveHeroToFile(const Hero& hero) {
    std::ofstream file("hero.txt");

    if (file.is_open()) {
        file << hero.GetHP() << " ";
        file << hero.GetEXP() << " ";
        file << hero.GetDamage() << " ";
        //file << hero.m_alive << std::endl;

        file.close();
        std::cout << "Hero data saved to file." << std::endl;
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }
}

#include "..\include\HeroFileFunction.hpp"

#include <fstream>
#include <iostream>

void saveHeroToFile(const Hero& hero) {
    std::ofstream file("progress.txt");

    if (file.is_open()) {
        file << hero.GetHP() << std::endl;
        file << hero.GetEXP() << std::endl;
        file << hero.GetDamage() << std::endl;
        //file << hero.m_alive << std::endl;

        file.close();
        std::cout << "Hero data saved to file." << std::endl;
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }
}

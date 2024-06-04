#include "../include/Room3.hpp"
#include "../include/Hero.hpp"
#include "../include/enemy.hpp"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <unordered_map>


void Room3::ReadFile3(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file("room3.txt");

    Skeleton skeleton;

    bool battleStarted = false;
    bool battleEnded = false;
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        int command = std::atoi(line.c_str());

        if (command == COMMAND::FIGHT_BEGIN) {
            std::cout << "БОЙ НАЧИНАЕТСЯ" << std::endl;
            battleAndSave(hero, skeleton, gameOver);
            battleStarted = true;
            continue;
        }
        else if (command == COMMAND::FIGHT_END) {
            std::cout << "БОЙ ОКОНЧЕН" << std::endl;
            battleEnded = true;
            battleStarted = false;
            std::cout << "БОЙ ОКОНЧЕН" << std::endl;
            hero.saveToFile("hero.txt", roomVisited);
            continue;
        }

        std::cout << line << std::endl;

        if (battleStarted && !battleEnded) {
            _getch();
        }
    }
    file.close();
}

void Room3::battleAndSave(Hero& hero, Skeleton& skeleton, bool& gameOver) {
    hero.printCharacteristic();
    std::cout << "Хар-ки врага: " << std::endl;
    skeleton.printCharacteristic();
    std::cout << std::endl;

    while (hero.isAlive() && skeleton.isAlive()) {
        // Ход героя
        unsigned heroDamage = hero.GetDamage();
        skeleton.takingDamage(heroDamage);
        std::cout << "Базослав атакует Скелетона на " << heroDamage << " урона." << std::endl;

        if (!skeleton.isAlive()) {
            std::cout << "Базослав убил Скелетона!" << std::endl;
            hero.gainExperience(skeleton.GetEXP());
            break;
        }

        // Ход гоблина
        unsigned skeletonDamage = skeleton.GetDamage();
        hero.takingDamage(skeletonDamage);
        std::cout << "Cкелетон атакует Базослава на " << skeletonDamage << " урона." << std::endl;

        if (!hero.isAlive()) {
            std::cout << "Скелетон убил Базослава!" << std::endl;
            if (remove("hero.txt") == 0) {
                std::cout << "Вы умерли. Ваш прогресс стерт с лица Земли" << std::endl;
                gameOver = true; // Установить флаг завершения игры
            }
            else {
                std::cout << "Не удалось удалить файл hero.txt." << std::endl;
            }
            break;
        }
        hero.printCharacteristic();
    }
}

void Room3::initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    hero.loadFromFile("hero.txt", roomVisited); // загрузка данных героя перед началом
    ReadFile3(hero, gameOver, roomVisited);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}
#include "../include/Room1.hpp"
#include "../include/Hero.hpp"
#include "../include/enemy.hpp"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <Windows.h>
#include <unordered_map>

void Room1::ReadFile1(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file("room1.txt");

    Goblin goblin;

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
            battleAndSave(hero, goblin, gameOver);
            if (gameOver) break; // Если игра закончена, выйти из цикла
            battleStarted = true;
            continue;
        }
        else if (command == COMMAND::FIGHT_END) {
            std::cout << "БОЙ ОКОНЧЕН" << std::endl;
            battleEnded = true;
            battleStarted = false;
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

void Room1::battleAndSave(Hero& hero, Goblin& goblin, bool& gameOver) {
    hero.printCharacteristic();
    std::cout << "Хар-ки врага: " << std::endl;
    goblin.printCharacteristic();
    std::cout << std::endl;

    while (hero.isAlive() && goblin.isAlive()) {
        // Ход героя
        unsigned heroDamage = hero.GetDamage();
        goblin.takingDamage(heroDamage);
        std::cout << "Базослав атакует Гоблина на " << heroDamage << " урона." << std::endl;

        if (!goblin.isAlive()) {
            std::cout << "Базослав убил Гоблина!" << std::endl;
            hero.gainExperience(goblin.GetEXP());
            break;
        }

        // Ход гоблина
        unsigned goblinDamage = goblin.GetDamage();
        hero.takingDamage(goblinDamage);
        std::cout << "Гоблин атакует Базослава на " << goblinDamage << " урона." << std::endl;

        if (!hero.isAlive()) {
            std::cout << "Гоблин убил Базослава!" << std::endl;
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

void Room1::initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    hero.loadFromFile("hero.txt", roomVisited); // загрузка данных героя перед началом
    ReadFile1(hero, gameOver, roomVisited);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file("Room1.txt");

    file.close();
}

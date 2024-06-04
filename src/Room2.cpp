#include "../include/Room2.hpp"
#include "../include/Hero.hpp"
#include "../include/enemy.hpp"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <unordered_map>


void Room2::ReadFile2(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file("room2.txt");

    Bat bat;

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
            battleAndSave(hero, bat, gameOver);
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

void Room2::battleAndSave(Hero& hero, Bat& bat, bool& gameOver) {
    hero.printCharacteristic();
    std::cout << "Хар-ки врага: " << std::endl;
    bat.printCharacteristic();
    std::cout << std::endl;

    while (hero.isAlive() && bat.isAlive()) {
        // Ход героя
        unsigned heroDamage = hero.GetDamage();
        bat.takingDamage(heroDamage);
        std::cout << "Базослав атакует Летучую мышь на " << heroDamage << " урона." << std::endl;

        if (!bat.isAlive()) {
            std::cout << "Базослав убил Летучую мышь!" << std::endl;
            hero.gainExperience(bat.GetEXP());
            break;
        }


        unsigned batDamage = bat.GetDamage();
        hero.takingDamage(batDamage);
        std::cout << "Летучая мышь атакует Базослава на " << batDamage << " урона." << std::endl;

        if (!hero.isAlive()) {
            std::cout << "Летучая мышь убил Базослава!" << std::endl;
            break;
        }
        hero.printCharacteristic();
    }
}

void Room2::initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    hero.loadFromFile("hero.txt", roomVisited); // загрузка данных героя перед началом
    ReadFile2(hero, gameOver, roomVisited);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}
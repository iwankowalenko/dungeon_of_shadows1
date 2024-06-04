#include "../include/Room5.hpp"
#include "../include/Hero.hpp"
#include "../include/enemy.hpp"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <unordered_map>


void Room5::ReadFile5(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file("room5.txt");

    Snake snake;

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
            battleAndSave(hero, snake, gameOver);
            battleStarted = true;
            continue;
        }
        else if (command == COMMAND::FIGHT_END) {
            std::cout << "БОЙ ОКОНЧЕН" << std::endl;
            battleEnded = true;
            battleStarted = false;
            std::cout << "Хранитель озера был повержен!" << std::endl;
            std::cout << "Подземелье освобождено, а главный герой проснулся." << std::endl;
            std::cout << "Неужели это был всего лишь сон..." << std::endl;
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

void Room5::battleAndSave(Hero& hero, Snake& snake, bool& gameOver) {
    hero.printCharacteristic();
    std::cout << "Хар-ки врага: " << std::endl;
    snake.printCharacteristic();
    std::cout << std::endl;

    while (hero.isAlive() && snake.isAlive()) {
        // Ход героя
        unsigned heroDamage = hero.GetDamage();
        snake.takingDamage(heroDamage);
        std::cout << "Базослав атакует Змея на " << heroDamage << " урона." << std::endl;

        if (!snake.isAlive()) {
            std::cout << "Базослав убил Змея!" << std::endl;
            hero.gainExperience(snake.GetEXP());
            break;
        }

        // Ход гоблина
        unsigned snakeDamage = snake.GetDamage();
        hero.takingDamage(snakeDamage);
        std::cout << "CЗмей атакует Базослава на " << snakeDamage << " урона." << std::endl;

        if (!hero.isAlive()) {
            std::cout << "Змей убил Базослава!" << std::endl;
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

void Room5::initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    hero.loadFromFile("hero.txt", roomVisited); // загрузка данных героя перед началом
    ReadFile5(hero, gameOver, roomVisited);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

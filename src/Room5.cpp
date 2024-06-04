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
        std::cout << "������ �������� �����." << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        int command = std::atoi(line.c_str());

        if (command == COMMAND::FIGHT_BEGIN) {
            std::cout << "��� ����������" << std::endl;
            battleAndSave(hero, snake, gameOver);
            battleStarted = true;
            continue;
        }
        else if (command == COMMAND::FIGHT_END) {
            std::cout << "��� �������" << std::endl;
            battleEnded = true;
            battleStarted = false;
            std::cout << "��������� ����� ��� ��������!" << std::endl;
            std::cout << "���������� �����������, � ������� ����� ���������." << std::endl;
            std::cout << "������� ��� ��� ����� ���� ���..." << std::endl;
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
    std::cout << "���-�� �����: " << std::endl;
    snake.printCharacteristic();
    std::cout << std::endl;

    while (hero.isAlive() && snake.isAlive()) {
        // ��� �����
        unsigned heroDamage = hero.GetDamage();
        snake.takingDamage(heroDamage);
        std::cout << "�������� ������� ���� �� " << heroDamage << " �����." << std::endl;

        if (!snake.isAlive()) {
            std::cout << "�������� ���� ����!" << std::endl;
            hero.gainExperience(snake.GetEXP());
            break;
        }

        // ��� �������
        unsigned snakeDamage = snake.GetDamage();
        hero.takingDamage(snakeDamage);
        std::cout << "C���� ������� ��������� �� " << snakeDamage << " �����." << std::endl;

        if (!hero.isAlive()) {
            std::cout << "���� ���� ���������!" << std::endl;
            if (remove("hero.txt") == 0) {
                std::cout << "�� ������. ��� �������� ����� � ���� �����" << std::endl;
                gameOver = true; // ���������� ���� ���������� ����
            }
            else {
                std::cout << "�� ������� ������� ���� hero.txt." << std::endl;
            }
            break;
        }
        hero.printCharacteristic();
    }
}

void Room5::initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    hero.loadFromFile("hero.txt", roomVisited); // �������� ������ ����� ����� �������
    ReadFile5(hero, gameOver, roomVisited);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

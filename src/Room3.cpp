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
        std::cout << "������ �������� �����." << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        int command = std::atoi(line.c_str());

        if (command == COMMAND::FIGHT_BEGIN) {
            std::cout << "��� ����������" << std::endl;
            battleAndSave(hero, skeleton, gameOver);
            battleStarted = true;
            continue;
        }
        else if (command == COMMAND::FIGHT_END) {
            std::cout << "��� �������" << std::endl;
            battleEnded = true;
            battleStarted = false;
            std::cout << "��� �������" << std::endl;
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
    std::cout << "���-�� �����: " << std::endl;
    skeleton.printCharacteristic();
    std::cout << std::endl;

    while (hero.isAlive() && skeleton.isAlive()) {
        // ��� �����
        unsigned heroDamage = hero.GetDamage();
        skeleton.takingDamage(heroDamage);
        std::cout << "�������� ������� ��������� �� " << heroDamage << " �����." << std::endl;

        if (!skeleton.isAlive()) {
            std::cout << "�������� ���� ���������!" << std::endl;
            hero.gainExperience(skeleton.GetEXP());
            break;
        }

        // ��� �������
        unsigned skeletonDamage = skeleton.GetDamage();
        hero.takingDamage(skeletonDamage);
        std::cout << "C������� ������� ��������� �� " << skeletonDamage << " �����." << std::endl;

        if (!hero.isAlive()) {
            std::cout << "�������� ���� ���������!" << std::endl;
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

void Room3::initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    hero.loadFromFile("hero.txt", roomVisited); // �������� ������ ����� ����� �������
    ReadFile3(hero, gameOver, roomVisited);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}
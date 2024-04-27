#include "../include/Room1.hpp"
#include "../include/Hero.hpp"
#include "../include/enemy.hpp"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>

void Room1::ReadFile1(Hero& hero) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file("room1.txt");

    Goblin goblin;

    bool battleStarted = false;
    bool battleEnded = false;
    if (!file.is_open()) {
        std::cout << "������ �������� �����." << std::endl;
        return;
    }
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string line;



    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        if(goblin.isAlive()){
        if (!battleStarted && line == "��� ����������") {
            battleAndSave(hero, goblin);
            battleStarted = true;
        }

        if (battleStarted && !battleEnded && line == "��� �������") {
            battleEnded = true;
            // ���������� ��������� ����� ����� ��������� ���
        }
        _getch();
    }
    }
    file.close();
}

void Room1::battleAndSave(Hero& hero, Goblin& goblin) {
     hero.printCharacteristic();
     std::cout << std::endl;
    while (hero.isAlive() && goblin.isAlive()) {
        // ��� �����
        unsigned heroDamage = hero.GetDamage();
        goblin.takingDamage(heroDamage);
        std::cout << "�������� ������� ������� �� " << heroDamage << " �����." << std::endl;

        if (!goblin.isAlive()) {
            std::cout << "�������� ���� �������!" << std::endl;
            break;
        }

        // ��� �������
        unsigned goblinDamage = goblin.GetDamage();
        hero.takingDamage(goblinDamage);
        std::cout << "������ ������� ��������� �� " << goblinDamage << " �����." << std::endl;

        if (!hero.isAlive()) {
            std::cout << "������ ���� ���������!" << std::endl;
            break;
        }
    }
}

void Room1::initDialog(Hero& hero) {
    ReadFile1(hero);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file("Room1.txt");
    

    file.close();
}
#include "../include/Room2.hpp"
#include "../include/Hero.hpp"
#include "../include/enemy.hpp"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>

void Room2::ReadFile1(Hero& hero) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file("room1.txt");

    Bat bat;

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
        if (bat.isAlive()) {
            if (!battleStarted && line == "��� ����������") {
                battleAndSave(hero, bat);
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

void Room1::battleAndSave(Hero& hero, Bat& bat) {
    hero.printCharacteristic();
    std::cout << std::endl;
    while (hero.isAlive() && goblin.isAlive()) {
        
        unsigned heroDamage = hero.GetDamage();
        goblin.takingDamage(heroDamage);
        std::cout << "�������� ������� ������� ���� �� " << heroDamage << " �����." << std::endl;

        if (!goblin.isAlive()) {
            std::cout << "�������� ���� ������� ����!" << std::endl;
            break;
        }

        
        unsigned goblinDamage = goblin.GetDamage();
        hero.takingDamage(goblinDamage);
        std::cout << "������� ���� ������� ��������� �� " << goblinDamage << " �����." << std::endl;

        if (!hero.isAlive()) {
            std::cout << "������� ���� ���� ���������!" << std::endl;
            break;
        }
    }
}

void Room2::initDialog(Hero& hero) {
    ReadFile2(hero);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream file("Room1.txt");
    file.close();
}
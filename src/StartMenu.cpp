#include "../include/startMenu.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <chrono>
#include <thread>

void loadHeroFromFile(Hero& hero, std::unordered_map<int, bool>& roomVisited) {
    std::ifstream file("../progress/progress.txt");
    if (file.is_open()) {
        unsigned HP, EXP, Damage;
        if (file >> HP >> EXP >> Damage) {
            hero = Hero(HP, EXP, Damage);
            std::cout << "��������� ����� ������� ��������� �� �����" << std::endl;
        }
        else {
            std::cout << "������ �������� ���������� ����� �� �����" << std::endl;
        }
        // �������� ��������� ������
        int roomId;
        bool visited;
        while (file >> roomId >> visited) {
            roomVisited[roomId] = visited;
        }
        file.close();
    }
    else {
        std::cout << "�� ������� ������� ���� ��� �������� ���������� �����" << std::endl;
    }
}

void saveNewHeroToFile() {
    Hero hero(100, 0, 15);
    std::unordered_map<int, bool> roomVisited = {
        {1, false},
        {2, false},
        {3, false},
        {4, false}
    };

    hero.saveToFile("hero.txt", roomVisited);
}

std::string StartMenu::m_lower(std::string str) {
    for (char& i : str) {
        if (i < 'a') {
            i += 32;
        }
    }
    return str;
}

void StartMenu::initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    bool flagSet = true;
    int answerSet;

    while (flagSet) {
        std::cout << "����� ���������� � Dungeon of Shadows" << std::endl;
        std::cout << "1. ���������� ����" << std::endl;
        std::cout << "2. ������ ����� ����!" << std::endl;
        std::cout << "0. ����� �� ����" << std::endl;

        std::cout << "������� ������ ��������: ";
        std::cin >> answerSet;

        while (answerSet < 0 || answerSet > 2) {
            std::cout << "������� ���������� �������, ����������" << std::endl;
            std::cin >> answerSet;
        }

        switch (answerSet) {
        case COMMAND::START_CONTINUE:
            loadHeroFromFile(hero, roomVisited);
            std::cout << "����������� ����...\n";
            flagSet = false;
            break;
        case COMMAND::START_NEW_GAME:
            hero = Hero(100, 0, 15);
            roomVisited.clear();
            saveNewHeroToFile(); // ��������� ��������� ��������
            std::cout << "����� ���� ������!\n";
            flagSet = false;
            break;
        case COMMAND::EXIT:
            std::cout << "����-����, ������� ��� ��������!\n";
            exit(0);
        }
    }
}

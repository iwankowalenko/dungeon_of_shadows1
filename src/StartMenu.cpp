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

void loadHeroFromFile(Hero& hero) {
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
        file.close();
    }
    else {
        std::cout << "�� ������� ������� ���� ��� �������� ���������� �����" << std::endl;
    }
}

std::string StartMenu::m_lower(std::string str) {

    for (char& i : str) {
        if (i < 'a') {
            i += 32;
        }
    }
    
    return str;
}

void StartMenu::initDialog(Hero& hero) {

    bool flagSet = true;
    int answerSet;

    std::string strAnswer;

    while (flagSet) {
        std::cout << "����� ���������� � Dungeon of Shadows" << std::endl;
        std::cout << "1. ���������� ����" << std::endl;
        std::cout << "2. ������ ����� ����!" << std::endl;
        std::cout << "0. ����� �� ����" << std::endl;

        std::cout << "������� ������ ��������: ";

        std::cin >> answerSet;



        while (-1 > answerSet || answerSet > 4) {
            std::cout << "������� ���������� �������, ����������" << std::endl;
            std::cin >> answerSet;
        }

        std::string line;
        std::ifstream file("../progress/progress.txt");

        switch (answerSet) {
        case COMMAND::START_CONTINUE:
            if (file.is_open()) {
                loadHeroFromFile(hero);
            }
            printNextLineFromFile();
            std::cout << std::endl;
            std::cout << std::endl;
            return; //����� � ����
            break;

        case COMMAND::START_NEW_GAME:
            saveHeroToFile(hero);
            break;

        case COMMAND::EXIT:
            std::cout << "����-����, ������� ��� ��������!\n";
            exit(0);
            
        }

    }
}


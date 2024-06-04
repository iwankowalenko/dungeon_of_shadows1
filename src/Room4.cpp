#include "../include/Room4.hpp"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <unordered_map>

void Room4::initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "�� ����� � ������� 4 � ����� ���� ����� �������...\n";
    presentRiddle(hero);
}

void Room4::presentRiddle(Hero& hero) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    RiddleBed riddle;
    riddle.printRiddle();

    std::string answer;
    std::cout << "��� �����: ";
    std::cin >> answer;

    if (riddle.isTrue(answer, hero)) {
        std::cout << "�����������! �� ��������� �������� �� �������.\n";
        std::cout << "�� ��������� 100 ����� � ��������� �����������.\n";
    }
    else {
        std::cout << "������������ �����. ���������� ��� ��� � ��������� ���.\n";
    }
}

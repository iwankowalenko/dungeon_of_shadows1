#include "../include/Prologue.hpp"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>

bool continueReading = true;

void printNextLineFromFile() {
    std::ifstream file("story.txt");
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

        if (line == "��� �� ��� �����? �� ������� �� ��� ������ ���?") {
            std::string decision;
            bool validInput = false;

            do {
                std::cout << "��� �� ������� ���, ������� � ������ ��� ������ ������ � �������: " << std::endl;
                std::cin >> decision;

                if (decision == "�������") {
                    std::cout << "�� ��������..." << std::endl;
                    validInput = true;
                }
                else if (decision == "������") {
                    std::cout << "� �����, ����� � ������� �� ���� ����������!" << std::endl;
                    std::cout << "������ � ������� �� ����� ����, ��� ����� ��� ����� ������" << std::endl;
                    continueReading = true;
                    validInput = true;
                }
                else {
                    std::cout << "�� ������ �����... ��� �� ��� �������?" << std::endl;
                }
            } while (!validInput);
        }
        _getch();
    }

    file.close();
}
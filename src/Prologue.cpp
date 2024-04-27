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
        std::cout << "Ошибка открытия файла." << std::endl;
        return;
    }
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string line;

    while (std::getline(file, line)) {

        std::cout << line << std::endl;

        if (line == "Что же это такое? Не видится же мне одному это?") {
            std::string decision;
            bool validInput = false;

            do {
                std::cout << "Что же сделать мне, подойти к дереву или искать дорогу в деревню: " << std::endl;
                std::cin >> decision;

                if (decision == "подойти") {
                    std::cout << "Ну допустим..." << std::endl;
                    validInput = true;
                }
                else if (decision == "искать") {
                    std::cout << "К черту, пойду в деревню от этой чертовщины!" << std::endl;
                    std::cout << "Только я побежал из этого леса, как вдруг все стало черным" << std::endl;
                    continueReading = true;
                    validInput = true;
                }
                else {
                    std::cout << "Не совсем понял... Что же мне сделать?" << std::endl;
                }
            } while (!validInput);
        }
        _getch();
    }

    file.close();
}
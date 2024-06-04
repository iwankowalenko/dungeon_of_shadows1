#include "../include/HeroFileFunction.hpp"
#include "../include/riddles.hpp"
#include "../include/startMenu.hpp"
#include "../include/Hero.hpp"
#include "../include/Prologue.hpp"
#include "../include/Room1.hpp"
#include "../include/Room2.hpp"
#include "../include/Room3.hpp"
#include "../include/Room4.hpp"
#include "../include/Room5.hpp"

#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <Windows.h>

void displayMenu() {
    std::cout << "Выберите комнату для перехода:\n";
    std::cout << "1. Пролог\n";
    std::cout << "2. Room1\n";
    std::cout << "3. Room2\n";
    std::cout << "4. Room3\n";
    std::cout << "5. Room4\n";
    std::cout << "6. Room5\n";
    std::cout << "0. Выход\n";
}

void initPrologue(Hero& hero, bool& gameOver) {
    std::cout << "Запуск пролога...\n";
    printNextLineFromFile();
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Hero hero(100, 0, 15);
    StartMenu startMenu;
    Room1 room1;
    Room2 room2;
    Room3 room3;
    Room4 room4;
    Room5 room5;

    bool gameOver = false;
    std::unordered_map<int, bool> roomVisited = {
        {1, false}, // Пролог
        {2, false}, // Room1
        {3, false}, // Room2
        {4, false}, // Room3
        {5, false}, // Room4
        {6, false}  // Room5
    };

    startMenu.initDialog(hero, gameOver, roomVisited);

    while (true) {
        while (!gameOver) {
            displayMenu();
            int choice;
            std::cin >> choice;

            if (choice == 0) {
                std::cout << "Выход из игры..." << std::endl;
                return 0;
            }

            if (roomVisited[choice]) {
                std::cout << "Я здесь уже был... Здесь ничего не осталось.\n";
                continue;
            }

            switch (choice) {
            case 1:
                initPrologue(hero, gameOver);
                roomVisited[1] = true;
                break;
            case 2:
                room1.initDialog(hero, gameOver, roomVisited);
                roomVisited[2] = true;
                break;
            case 3:
                room2.initDialog(hero, gameOver, roomVisited);
                roomVisited[3] = true;
                break;
            case 4:
                room3.initDialog(hero, gameOver, roomVisited);
                roomVisited[4] = true;
                break;
            case 5:
                room4.initDialog(hero, gameOver, roomVisited);
                roomVisited[5] = true;
                break;
            case 6:
                room5.initDialog(hero, gameOver, roomVisited);
                roomVisited[6] = true;
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, выберите снова.\n";
                continue;
            }

            hero.saveToFile("hero.txt", roomVisited);

            if (gameOver) {
                std::cout << "Игра окончена. Возвращение в меню..." << std::endl;
                gameOver = false;
                break;
            }
        }
        startMenu.initDialog(hero, gameOver, roomVisited);
    }
    return 0;
}

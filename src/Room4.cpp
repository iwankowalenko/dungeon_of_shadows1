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
    std::cout << "Вы вошли в комнату 4 и перед вами стоит загадка...\n";
    presentRiddle(hero);
}

void Room4::presentRiddle(Hero& hero) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    RiddleBed riddle;
    riddle.printRiddle();

    std::string answer;
    std::cout << "Ваш ответ: ";
    std::cin >> answer;

    if (riddle.isTrue(answer, hero)) {
        std::cout << "Поздравляем! Вы правильно ответили на загадку.\n";
        std::cout << "Вы получаете 100 опыта и полностью исцеляетесь.\n";
    }
    else {
        std::cout << "Неправильный ответ. Попробуйте еще раз в следующий раз.\n";
    }
}

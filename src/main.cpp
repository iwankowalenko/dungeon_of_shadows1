#include "../include/HeroFileFunction.hpp"
#include "../include/riddles.hpp"
#include "../include/startMenu.hpp"
#include "../include/Hero.hpp"
#include "../include/startMenu.hpp"
#include "../include/Prologue.hpp"
#include "../include/Room1.hpp"

#include <iostream>
#include <stdio.h>


int main() {
	setlocale(LC_ALL, "Russian");

	Hero hero(100,0,15);
	hero.printCharacteristic();
	StartMenu startMenu;
	Room1 room1;
	
	startMenu.initDialog(hero);
	hero.printCharacteristic();

	std::cout << "Вы хотите продолжить?" << std::endl;
	std::string answer;
	std::cin >> answer;
	if (answer == "да") {
		room1.initDialog(hero);
	}
	else if(answer == "нет"){
		std::cout << "It's over...";
	}




}

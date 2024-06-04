#pragma once

#include "../include/Hero.hpp"
#include "../include/enemy.hpp"

#include <string>
#include <iostream>
#include <unordered_map>

	
class Room1 {
public:
	void initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited);
private:
	void battleAndSave(Hero& hero, Goblin& goblin, bool& gameOver);
	void ReadFile1(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited);

	enum COMMAND {
		FIGHT_BEGIN = 1,
		FIGHT_END = 2
	};
};
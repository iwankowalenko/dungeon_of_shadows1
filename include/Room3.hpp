#pragma once

#include "../include/Hero.hpp"
#include "../include/enemy.hpp"

#include <string>
#include <iostream>
#include <unordered_map>


class Room3 {
public:
	void initDialog(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited);
private:
	void battleAndSave(Hero& hero, Skeleton& skeleton, bool& gameOver);
	void ReadFile3(Hero& hero, bool& gameOver, std::unordered_map<int, bool>& roomVisited);
	enum COMMAND {
		FIGHT_BEGIN = 1,
		FIGHT_END = 2
	};
};
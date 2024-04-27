#pragma once

#include "../include/Hero.hpp"
#include "../include/enemy.hpp"

#include <string>
#include <iostream>

	
class Room1 {
public:
	Room1() = default;

	Room1(const Room1& other) = delete;

	void initDialog(Hero& hero);
	void ReadFile1(Hero& hero);

private:
	void battleAndSave(Hero& hero, Goblin& goblin);
};
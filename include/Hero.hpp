#pragma once

#include <iostream>
#include <vector>


class Hero {
public:
	Hero() = default;

	Hero(unsigned HP, unsigned EXP, unsigned Damage) {
		m_HP = HP;
		m_EXP = EXP;
		m_Damage = Damage;
	}

	unsigned GetHP() const;

	unsigned GetEXP() const;

	unsigned GetDamage() const;

	void printCharacteristic() const;

	void takingDamage(unsigned Damage);

	bool isAlive() const {
		return m_alive;
	}
private:
	unsigned m_HP;
	unsigned m_EXP;
	unsigned m_Damage;

	bool m_alive = true;

};
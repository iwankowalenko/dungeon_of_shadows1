#include "../include/Hero.hpp"


#include <iostream>
#include <vector>


unsigned Hero::GetHP() const { return (this->m_HP); }

unsigned Hero::GetEXP() const { return (this->m_EXP); }

unsigned Hero::GetDamage() const { return (this->m_Damage); }

void Hero::printCharacteristic() const {
    std::cout << m_HP;
    std::cout << m_EXP;
    std::cout << m_Damage;
}

void Hero::takingDamage(unsigned Damage) {

    if (Damage >= (this->m_HP)) {
        m_alive = false;
    }
    else {
        this->m_HP -= Damage;
    }
}

void UpdateCharacterisic(unsigned HP, unsigned EXP, unsigned Damage) {

}


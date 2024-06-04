#include "../include/enemy.hpp"

#include <string>
#include <iostream>

// Goblin

unsigned Goblin::GetHP() const { return (this->m_HP); }

unsigned Goblin::GetEXP() const { return (this->m_EXP); }

unsigned Goblin::GetDamage() const { return (this->m_Damage); }

void Goblin::printCharacteristic() const {
    std::cout << "HP: " << m_HP << std::endl;
    std::cout << "EXP: " << m_EXP << std::endl;
    std::cout << "Damage: " << m_Damage << std::endl;
}

void Goblin::takingDamage(unsigned Damage) {

  if (Damage >= (this->m_HP)) {
    m_alive = false;
  } else {
    this->m_HP -= Damage;
  }
}

// Bat

unsigned Bat::GetHP() const { return (this->m_HP); }

unsigned Bat::GetEXP() const { return (this->m_EXP); }

unsigned Bat::GetDamage() const { return (this->m_Damage); }

void Bat::printCharacteristic() const {
    std::cout << "HP: " << m_HP << std::endl;
    std::cout << "EXP: " << m_EXP << std::endl;
    std::cout << "Damage: " << m_Damage << std::endl;
}

void Bat::takingDamage(unsigned Damage) {

  if (Damage >= (this->m_HP)) {
    m_alive = false;
  } else {
    this->m_HP -= Damage;
  }
}

// Skeleton

unsigned Skeleton::GetHP() const { return (this->m_HP); }

unsigned Skeleton::GetEXP() const { return (this->m_EXP); }

unsigned Skeleton::GetDamage() const { return (this->m_Damage); }

void Skeleton::printCharacteristic() const {
    std::cout << "HP: " << m_HP << std::endl;
    std::cout << "EXP: " << m_EXP << std::endl;
    std::cout << "Damage: " << m_Damage << std::endl;
}

void Skeleton::takingDamage(unsigned Damage) {

  if (Damage >= (this->m_HP)) {
    m_alive = false;
  } else {
    this->m_HP -= Damage;
  }
}

// Troll

unsigned Troll::GetHP() const { return (this->m_HP); }

unsigned Troll::GetEXP() const { return (this->m_EXP); }

unsigned Troll::GetDamage() const { return (this->m_Damage); }

void Troll::printCharacteristic() const {
    std::cout << "HP: " << m_HP << std::endl;
    std::cout << "EXP: " << m_EXP << std::endl;
    std::cout << "Damage: " << m_Damage << std::endl;
}

void Troll::takingDamage(unsigned Damage) {

  if (Damage >= (this->m_HP)) {
    m_alive = false;
  } else {
    this->m_HP -= Damage;
  }
}

// Snake

unsigned Snake::GetHP() const { return (this->m_HP); }

unsigned Snake::GetEXP() const { return (this->m_EXP); }

unsigned Snake::GetDamage() const { return (this->m_Damage); }

void Snake::printCharacteristic() const {
    std::cout << "HP: " << m_HP << std::endl;
    std::cout << "EXP: " << m_EXP << std::endl;
    std::cout << "Damage: " << m_Damage << std::endl;
}

void Snake::takingDamage(unsigned Damage) {

    if (Damage >= (this->m_HP)) {
        m_alive = false;
    }
    else {
        this->m_HP -= Damage;
    }
}
#include "../include/Hero.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

Hero::Hero(unsigned HP, unsigned EXP, unsigned Damage)
    : m_HP(HP), m_EXP(EXP), m_Damage(Damage), m_MaxHP(HP), m_alive(true) {
}

unsigned Hero::GetHP() const {
    return this->m_HP;
}

unsigned Hero::GetEXP() const {
    return this->m_EXP;
}

unsigned Hero::GetDamage() const {
    return this->m_Damage;
}

unsigned Hero::GetMaxHP() const {
    return this->m_MaxHP;
}

void Hero::SetHP(unsigned hp) {
    this->m_HP = hp;
}

void Hero::SetEXP(unsigned exp) {
    this->m_EXP = exp;
}

bool Hero::isAlive() const {
    return this->m_alive;
}

void Hero::printCharacteristic() const {
    std::cout << "HP: " << m_HP << std::endl;
    std::cout << "EXP: " << m_EXP << std::endl;
    std::cout << "Damage: " << m_Damage << std::endl;
}

void Hero::takingDamage(unsigned Damage) {
    if (Damage >= this->m_HP) {
        m_alive = false;
        this->m_HP = 0;
    }
    else {
        this->m_HP -= Damage;
    }
}

void Hero::gainExperience(unsigned EXP) {
    m_EXP += EXP;
    if (m_EXP >= 100) {
        m_HP += 10;
        m_MaxHP += 10;  // Увеличиваем максимальное HP при повышении уровня
        m_Damage += 5;
        m_EXP = 0; // сбросить опыт после повышения уровня
    }
}

void Hero::saveToFile(const std::string& filename, const std::unordered_map<int, bool>& roomVisited) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << m_HP << " " << m_EXP << " " << m_Damage << " " << m_MaxHP << std::endl;
        for (const auto& room : roomVisited) {
            file << room.first << " " << room.second << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
    }
}

void Hero::loadFromFile(const std::string& filename, std::unordered_map<int, bool>& roomVisited) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> m_HP >> m_EXP >> m_Damage >> m_MaxHP;
        int roomId;
        bool visited;
        while (file >> roomId >> visited) {
            roomVisited[roomId] = visited;
        }
        file.close();
    }
    else {
        std::cerr << "Ошибка открытия файла для чтения!" << std::endl;
    }
}

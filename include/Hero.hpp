#pragma once

#include <string>
#include <unordered_map>

class Hero {
public:
    Hero(unsigned HP = 100, unsigned EXP = 0, unsigned Damage = 10);  // конструктор по умолчанию добавлен

    unsigned GetHP() const;
    unsigned GetEXP() const;
    unsigned GetDamage() const;
    unsigned GetMaxHP() const;

    void SetHP(unsigned hp);
    void SetEXP(unsigned exp);

    bool isAlive() const;

    void printCharacteristic() const;

    void takingDamage(unsigned Damage);
    void gainExperience(unsigned EXP);

    void saveToFile(const std::string& filename, const std::unordered_map<int, bool>& roomVisited) const;
    void loadFromFile(const std::string& filename, std::unordered_map<int, bool>& roomVisited);

private:
    unsigned m_HP;
    unsigned m_EXP;
    unsigned m_Damage;
    unsigned m_MaxHP;  // Добавляем поле для максимального HP
    bool m_alive;
};

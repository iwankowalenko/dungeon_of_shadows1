#pragma once

class Enemy {
public:

  virtual unsigned GetHP() const = 0;
  virtual unsigned GetEXP() const = 0;
  virtual unsigned GetDamage() const = 0;

  virtual void printCharacteristic() const = 0;

  virtual void takingDamage(unsigned damage) = 0;
};

class Goblin : public Enemy {
public:
  unsigned GetHP() const override;

  unsigned GetEXP() const override;

  unsigned GetDamage() const override;

  void printCharacteristic() const override;

  void takingDamage(unsigned Damage) override;

  bool isAlive() const {
      return m_alive;
  }

private:
  unsigned m_HP = 30;
  unsigned m_EXP = 65;
  unsigned m_Damage = 15;

  bool m_alive = true;
};

class Bat : public Enemy {
public:
  unsigned GetHP() const override;

  unsigned GetEXP() const override;

  unsigned GetDamage() const override;

  void printCharacteristic() const override;

  void takingDamage(unsigned Damage) override;

  bool isAlive() const {
      return m_alive;
  }

private:
  unsigned m_HP = 30;
  unsigned m_EXP = 55;
  unsigned m_Damage = 10;

  bool m_alive = true;
};

class Skeleton : public Enemy {
public:
  unsigned GetHP() const override;

  unsigned GetEXP() const override;

  unsigned GetDamage() const override;

  void printCharacteristic() const override;

  void takingDamage(unsigned Damage) override;

  bool isAlive() const {
      return m_alive;
  }

private:
  unsigned m_HP = 50;
  unsigned m_EXP = 80;
  unsigned m_Damage = 10;

  bool m_alive = true;
};

class Troll : public Enemy {
public:
  unsigned GetHP() const override;

  unsigned GetEXP() const override;

  unsigned GetDamage() const override;

  void printCharacteristic() const override;

  void takingDamage(unsigned Damage) override;

private:
  unsigned m_HP = 50;
  unsigned m_EXP = 90;
  unsigned m_Damage = 45;

  bool m_alive = true;
};

class Snake : public Enemy {
public:
    unsigned GetHP() const override;

    unsigned GetEXP() const override;

    unsigned GetDamage() const override;

    void printCharacteristic() const override;

    void takingDamage(unsigned Damage) override;

    bool isAlive() const {
        return m_alive;
    }

private:
    unsigned m_HP = 100;
    unsigned m_EXP = 200;
    unsigned m_Damage = 15;

    bool m_alive = true;
};

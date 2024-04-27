#pragma once

#include <string>

class Riddles {
public:
  virtual ~Riddles();

  virtual void printRiddle() const = 0;
  virtual bool isTrue(std::string &UserAnswer) const = 0;

protected:
  static std::string &m_lower(std::string &Line);
};

class RiddleBed : public Riddles {
public:
  void printRiddle() const override;
  bool isTrue(std::string &UserAnswer) const override;

private:
  std::string m_answer = "кровать";

  std::string m_Riddle =
      "Утром с ней прощаюсь, \n вечером встречаюсь, \n С ней я к полу ниже, \n "
      "Она всех мне ближС ней я к полу ниже, \n Она всех мне ближС ней я к "
      "полу ниже, \n Она всех мне ближе. ";
};

class RiddleBook : public Riddles {
public:
  void printRiddle() const override;
  bool isTrue(std::string &UserAnswer) const override;

private:
  std::string m_answer = "книга";

  std::string m_Riddle = "Они могут рассказать всё обо всём, \n Но не "
                         "произнесут при этом ни слова. ";
};

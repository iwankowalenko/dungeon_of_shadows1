#include "../include/riddles.hpp"

// Riddles

std::string &Riddles::m_lower(std::string &Line) {

  for (char el : Line) {
    if (el < 'a') {
      el += 32;
    }
  }

  return Line;
}

// RiddlesBed

void RiddleBed::printRiddle() const {
  std::cout (this -> riddles);
}

bool RiddleBed::isTrue(std::string &UserAnswer) const {
  return ((this->m_answer) == m_lower(UserAnswer));
}

// RiddleBook

void RiddleBook::printRiddle() const {
  std::cout (this -> riddles)
}

bool RiddleBook::isTrue(std::string &UserAnswer) const {
  return (this->m_answer == m_lower(UserAnswer));
}

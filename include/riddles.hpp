#pragma once

#include <string>
#include "Hero.hpp" // Убедитесь, что путь к Hero.hpp правильный

class Riddles {
public:
    virtual ~Riddles() = default;

    virtual void printRiddle() const = 0;
    virtual bool isTrue(std::string& UserAnswer, Hero& hero) const = 0;

protected:
    static std::string& m_lower(std::string& Line);
};

class RiddleBed : public Riddles {
public:
    void printRiddle() const override;
    bool isTrue(std::string& UserAnswer, Hero& hero) const override;

private:
    std::string m_answer = "bed";

    std::string m_Riddle =
        "In the morning I say goodbye to her, in the evening I meet her, I'm closer to the floor than she is to me.";
};

class RiddleBook : public Riddles {
public:
    void printRiddle() const override;
    bool isTrue(std::string& UserAnswer, Hero& hero) const override;

private:

    std::string m_answer = "book";

    std::string m_Riddle = "They can tell you everything about everything, but they won't say a word.";
};

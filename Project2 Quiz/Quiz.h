#ifndef QUIZ_H
#define QUIZ_H
#include <string>

//Creates a class Quiz
class Quiz
{
private:
    //Declares answer and question and initializes to "" and a static score variable to keep track of the score
    std::string question {""};
    std::string answer {""};
    static int score;

public:
    //Creates a default constructor that sets answer and question to the two strings passed in
    Quiz() = default;
    Quiz(std::string q, std::string a) : question(q), answer(a)
    {};
    //Declares getter functions
    std::string getQuestion();
    std::string getAnswer();
    static int getScore();
    //Declares function to update the score and a function to print a resuly screen
    static void updateScore(int val);
    friend std::string printResult(int questions, int correct, int wrong);
};

#endif
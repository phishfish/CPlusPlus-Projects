#include <iostream>
#include <sstream>
#include <string>
#include "Quiz.h"
#include "printResult.h"

std::string printResult(int questions, int correct, int wrong)
{
    //Declares a stringstream called userResults
    std::stringstream userResults;

    //Formats userResults to display the summary 
    userResults << "Number of questions: " << std::to_string(questions) << std::endl;
    userResults << "Number correct answers: " << std::to_string(correct) << std::endl;
    userResults << "Number wrong answers: " << std::to_string(wrong) << std::endl;
    userResults << "Final score: " << Quiz::getScore() << std::endl;

    //Returns the stringstream as a string
    return userResults.str();
}
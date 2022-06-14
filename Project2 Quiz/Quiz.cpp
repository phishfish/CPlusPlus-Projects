#include "Quiz.h"

//Initializes the score to 0
int Quiz::score {0};

void Quiz::updateScore(int val)
{
    //If the score is higher than 0, then the score adds val to it, else if the score is 0, then val is checked and if it is positive, score is updated
    if (score > 0)
    {
        score += val;
    }
    else if (score == 0)
    {
        if (val > 0)
        {
            score += val;
        }
    }
}

//Returns the score
int Quiz::getScore()
{
    return score;
}

//Returns the answer
std::string Quiz::getAnswer()
{
    return answer;
}

//Returns the question
std::string Quiz::getQuestion()
{
    return question;
}


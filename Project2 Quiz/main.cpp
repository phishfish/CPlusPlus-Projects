//This program reads in question and answer pairs from a text file into a vector of Quiz objects. Then the user is asked questions and points are given or deducted based on if the input is correct or incorrect. At the end of the program, the program prints a summary
//Lucia Wang
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Quiz.h"
#include "printResult.h"
using namespace std;

//Function to achieve true randomness that doesn't just switch the order a question is asked first
int myRandom (int i) { return rand() % i;}

int main(int argc, char const *argv[])
{
    //Declares the command line argument to be the database to read question and answers from 
    string database;
    database = argv[1];
    
    //Declares an ifstream myFile
    ifstream myFile;
    string line;
    string answer,
    question;
    string userInput;

    //Declares a vector quizVector of Quiz objects
    vector<Quiz> quizVector;
    int numWrong = 0,
    numCorrect = 0;

    //Opens the text file
    myFile.open(database);

    if (myFile.is_open())
    {
        //Reads up to the first space from the file and stores it into line
        while(getline(myFile, line, ' '))
        {
            //Checks if the beginning of the string is Q: or A: and takes in the rest of the line after : into question or answer
            if (line[0] == 'Q' && line[1] == ':')
            {
	      getline(myFile, question);
            }
            if (line[0] == 'A' && line[1] == ':')
            {
	      getline(myFile, answer);
	      while (answer[answer.length() - 1] == '\r' || answer[answer.length() - 1] == '\n')
		{
		  answer.erase(answer.length() - 1);
		}
	     
                //Creates a new object Quiz and initializes with the answer and question pair taken in from the file
	      quizVector.push_back(Quiz(question , answer));
            }
        }
    }
    //If there was a problem opening the file, an error message is printed
    else
    {
        cout << "There was a problem opening the file." << endl;
    }

    //Randomly shuffles that order of the question-answer pairs
    srand(unsigned(time(0)));

    random_shuffle(quizVector.begin(), quizVector.end(), myRandom);

    //Stores the size of the vector (number of questions)
    int vectorSize = quizVector.size();

    //Loops through the vector and asks the user a randomly selected question and takes in the user answer  
    for (int i = 0; i < vectorSize; ++i)
    {
        cout << quizVector[i].getQuestion() << endl;
        getline(cin, userInput);
        //If the user input is correct, numCorrect is updated and the score goes up by one, 
        if (userInput == quizVector[i].getAnswer())
        {
            ++numCorrect;
            Quiz::updateScore(1);
            cout << "Correct!" << endl;
            cout << "Current score: " << Quiz::getScore() << endl << endl;
        }
        //If the user input is incorrect, numWrong is updated, the score is lowered by one, and the correct answer is displayed
        else 
        {
            ++numWrong;
            Quiz::updateScore(-1);
            cout << "Wrong! Correct answer: " << quizVector[i].getAnswer() << endl;
            cout << "Current score: " << Quiz::getScore() << endl << endl;
        }
    }

    //Calls printResult function to print a summary
    cout << printResult(vectorSize, numCorrect, numWrong);

    //Closes the file
    myFile.close();
    return 0;
}
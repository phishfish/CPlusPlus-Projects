//This program creates objects of cards in a vector that holds card objects named deck and then plays a card game with the user
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main() {

  //Creates and initializes counter variables
  char playAgain = 'Y';
  int userWins = 0;
  int totalPoints = 0;
  int numPlayed = 0;

  cout << "Welcome to TigerGame! \n";

  //Repeats while the user does not type N to stop the program
  while (playAgain != 'N')
  {
    ++numPlayed;

    //Creates a deck and shuffles it
    Deck deck;
    deck.shuffle();
    
    int userChoice;
    int numRounds;

    //Asks the user to input how many cards should be drawn
    cout << "How many card should each of you get? ";
    cin >> numRounds;

    //Input validation to check if a high number than 20 was typed
    while ((numRounds * 2) > 20)
    {
      cout << "That is too many cards, please enter soomething 10 or less: ";
      cin >> numRounds;
    }

    cout << "The deck was shuffled and each player has drawn " << numRounds << " cards.\n";

    //Creates two objects of player to represent the computer and the user
    Player playerUser(deck, numRounds);
    Player playerComp(deck, numRounds);

    //Iterates until every card is played
    for (int i = 0; i < numRounds; ++i)
    {
      cout << "\nRound " << i + 1 << '!' << endl;
      cout << "-------\n";

      //Creates a temp card for the computer by drawing the first card and prints it
      Card compCard = Card(playerComp.hand.dealCard(1));
      cout << "The computer plays: " << compCard.printCard() << endl;
      //Calls function to print all cards of the user
      cout << "Your hand: " << playerUser.hand.printHand() << endl;

      //Prompts user to choose a card
      cout << "Which card do you want to play? ";
      cin >> userChoice;

      //Input validation for cards not in hand
      while (userChoice > playerUser.hand.getHandSize() || userChoice <= 0) 
      {
        cout << "That choice is not in your hand. Please enter a valid number: ";
        cin >> userChoice;
      }

      //Temp card created for comparision 
      Card userCard = Card(playerUser.hand.dealCard(userChoice));
      cout << "You played: " << userCard.printCard() << endl; 

      //Compares cards and awards the person with a high card with both card values added as points, if they are equal, no one gets points
      if (userCard.getValue() > compCard.getValue())
      {
        cout << "You win this round!" << endl << endl;
        playerUser.score += (userCard.getValue() + compCard.getValue());
      }
      else if (userCard.getValue() < compCard.getValue())
      {
        cout << "The computer wins this round!" << endl << endl;
        playerComp.score += (userCard.getValue() + compCard.getValue());
      }
      else 
      {
        cout << "Tie!" << endl << endl;
      }

      //Prints the scores of the players
      cout << "Current scores:" << endl;
      cout << "Human: " << playerUser.score << endl;
      cout << "Computer: " << playerComp.score << endl;
    }

    //Prints out the scores of the players and adds them to the totalPoints counter
    cout << "\nFINAL SCORE:" << endl;
    cout << "Human: " << playerUser.score << endl;
    cout << "Computer: " << playerComp.score << endl << endl;
    totalPoints += (playerUser.score + playerComp.score);

    //Compares whose score was higher and declares the winner or a tie
    if (playerUser.score > playerComp.score)
    {
      cout << "Human has won!" << endl;
      ++userWins;
    }
    else if (playerUser.score < playerComp.score)
    {
      cout << "The computer has won!" << endl;
    }
    else 
    {
      cout << "The game ended in a tie!" << endl;
    }

    //Prompts the user to type Y to keep playing and N to stop
    cout << "Would you like to play again (Y or N)? ";
    cin >> playAgain;
    //Input Validation if the user inputs anything besides Y or N
    while (playAgain != 'Y' && playAgain != 'N')
    {
      cout << "Please enter Y to keep playing or N to stop: ";
      cin >> playAgain;
    }
    cout << endl;
  }

  //Prints how many rounds were played, number of times the user won, and the total points won
  cout << "Game summary:" << endl;
  cout << "Rounds played: " << numPlayed << endl;
  cout << "Number of rounds won by the human: " << userWins << endl;
  cout << "Total points won by both players: " << totalPoints << endl;

  return 0;
}
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

  char playAgain = 'Y';
  int userWins = 0;
  int totalPoints = 0;
  int numPlayed = 0;

  cout << "Welcome to TigerGame! \n";

  while (playAgain != 'N')
  {
    ++numPlayed;
    
    Deck deck;
    deck.shuffle();
    
    int userChoice;
    int numRounds;

    cout << "How many card should each of you get? ";
    cin >> numRounds;

    while ((numRounds * 2) > 20)
    {
      cout << "That is too many cards, please enter soomething 10 or less: ";
      cin >> numRounds;
    }

    cout << "The deck was shuffled and each player has drawn " << numRounds << " cards.\n";

    Player playerUser(deck, numRounds);
    Player playerComp(deck, numRounds);

    for (int i = 0; i < numRounds; ++i)
    {
      cout << "\nRound " << i + 1 << '!' << endl;
      cout << "-------\n";

      Card compCard = Card(*playerComp.hand.dealCard(1));
      cout << "The computer plays: " << compCard.printCard() << endl;

      if (compCard.printCard() == "Tiger:10")
      {
        playerComp.score += 20;
        cout << "Tiger Card played! The round will now end." << endl;
        break;
      }

      cout << "Your hand: " << playerUser.hand.printHand() << endl;

      cout << "Which card do you want to play? ";
      cin >> userChoice;

      while (userChoice > playerUser.hand.getHandSize() || userChoice <= 0) 
      {
        cout << "That choice is not in your hand. Please enter a valid number. ";
        cin >> userChoice;
      }

      cout << "You played: " << Card(*playerUser.hand.dealCard(userChoice)).printCard() << endl; 

      if (Card(*playerUser.hand.dealCard(userChoice)).printCard() == "Tiger:10")
      {
        playerUser.score += 20;
        cout << "Tiger Card played! The round will now end." << endl;
        break;
      }

      if (Card(*playerUser.hand.dealCard(userChoice)).getValue() > compCard.getValue())
      {
        cout << "You win this round!" << endl << endl;
        playerUser.score += (Card(*playerUser.hand.dealCard(userChoice)).getValue() + compCard.getValue());
      }
      else if (Card(*playerUser.hand.dealCard(userChoice)).getValue() < compCard.getValue())
      {
        cout << "The computer wins this round!" << endl << endl;
        playerComp.score += (Card(*playerUser.hand.dealCard(userChoice)).getValue() + compCard.getValue());
      }
      else 
      {
        cout << "Tie!" << endl << endl;
      }

      cout << "Current scores:" << endl;
      cout << "Human: " << playerUser.score << endl;
      cout << "Computer: " << playerComp.score << endl;
    }

    cout << "\nFINAL SCORE:" << endl;
    cout << "Human: " << playerUser.score << endl;
    cout << "Computer: " << playerComp.score << endl << endl;
    totalPoints += (playerUser.score + playerComp.score);

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

    cout << "Would you like to play again (Y or N)? ";
    cin >> playAgain;
    while (playAgain != 'Y' && playAgain != 'N')
    {
      cout << "Please enter Y to keep playing or N to stop: ";
      cin >> playAgain;
    }
    cout << endl;
  }

  cout << "Rounds played: " << numPlayed << endl;
  cout << "Number of rounds won by the human: " << userWins << endl;
  cout << "Total points won by both players: " << totalPoints << endl;

  return 0;
}

#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Card.h"

//Creates a object called Deck
class Deck
{
  private:
    //Creates a vector of cards called deck
    std::vector<Card> deck;

  public:
    //Populates the deck vector with orange and purple cards numbered 1-10
    Deck() 
    {
      for (int i = 1; i <= 10; ++i)
      {
        deck.push_back(Card(i, Card::Color::orange));
        deck.push_back(Card(i, Card::Color::purple));
      }
    }
    void shuffle();
    Card drawCard();
    int getDeckSize();
};
  

#endif // DECK_H_
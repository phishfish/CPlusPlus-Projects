#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Card.h"

class Deck
{
  private:
    std::vector<Card*> deck;

  public:
    Deck() 
    {
      for (int i = 0; i < 10; ++i)
      {
        deck.push_back(new Card(i + 1, Card::Color::orange));
        deck.push_back(new Card(i + 1, Card::Color::purple));
      }
      deck.push_back(new TigerCard(10, Card::Color::orange));
    }
    void shuffle();
    Card* drawCard();
    int getDeckSize();
};
  

#endif // DECK_H_

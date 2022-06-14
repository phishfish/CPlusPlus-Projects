#include <algorithm>
#include "Deck.h"

int myRandom(int i) {return rand() % i;}

void Deck::shuffle()
{
    srand(unsigned(time(0)));
    random_shuffle(deck.begin(), deck.end(), myRandom);
}

Card* Deck::drawCard()
{
    Card* temp;
    temp = deck.front();
    deck.erase(deck.begin());
    
    return temp;
}

int Deck::getDeckSize()
{
    return deck.size();
}
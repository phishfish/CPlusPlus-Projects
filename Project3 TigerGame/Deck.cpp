#include <algorithm>
#include "Deck.h"

//Ensures true randomness
int myRandom(int i) {return rand() % i;}

//Shuffles the deck according to the time so it is different each time
void Deck::shuffle()
{
    srand(unsigned(time(0)));
    random_shuffle(deck.begin(), deck.end(), myRandom);
}

//Creates a temp card to return while deleting the first card
Card Deck::drawCard()
{
    Card temp;
    temp = deck.front();
    deck.erase(deck.begin());
    
    return temp;
}

//Returns the size of the deck vector
int Deck::getDeckSize()
{
    return deck.size();
}
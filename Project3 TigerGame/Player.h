#ifndef PLAYER_H_
#define PLAYER_H_
#include "Hand.h"

//Creates an object Player 
class Player
{
    public:
        //Creates a hand object and a score to keep track of 
        Hand hand;
        int score {0};
        Player() = default;
        //Player constructor creates a hand of N cards from the deck 
        Player(Deck &deck, int N)
        {
            hand = Hand(deck, N);
        };
};
  

#endif 

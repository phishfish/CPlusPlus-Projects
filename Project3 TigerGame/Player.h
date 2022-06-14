#ifndef PLAYER_H_
#define PLAYER_H_
#include "Hand.h"

class Player
{
    public:
        Hand hand;
        int score {0};
        Player() = default;
        Player(Deck &deck, int N)
        {
            hand = Hand(deck, N);
        };
};
  

#endif 

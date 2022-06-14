#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <sstream>
#include "Card.h"
#include "Deck.h"

class Hand
{
    private:
        std::vector<Card*> hand;

    public:
        Hand() = default;
        Hand(Deck &deck, int N)
        {
            for (int i = 0; i < N; ++i)
            {
                hand.push_back(deck.drawCard());
            }
        };
        std::string printHand();
        Card* dealCard(int num); 
        int getHandSize();
};

#endif // HAND_H_

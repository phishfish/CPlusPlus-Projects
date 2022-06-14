#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <sstream>
#include "Card.h"
#include "Deck.h"

//Creates an object Hand
class Hand
{
    private:
        //Creates a vector of cards called hand
        std::vector<Card> hand;

    public:
        Hand() = default;
        //Hand constructor populates hand vector with cards from the deck
        Hand(Deck &deck, int N)
        {
            for (int i = 0; i < N; ++i)
            {
                hand.push_back(deck.drawCard());
            }
        };
        std::string printHand();
        Card dealCard(int num); 
        int getHandSize();
};

#endif // HAND_H_

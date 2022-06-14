#include "Hand.h"

std::string Hand::printHand()
{
    std::stringstream currentHand;

    for (int i = 0; i < Hand::getHandSize(); ++i)
    {
        currentHand << '[' << std::to_string(i + 1) << "] " << hand[i]->printCard() << ' ';
    }

    return currentHand.str();
}

Card* Hand::dealCard(int num)
{
    Card* temp = hand[num - 1];

    hand.erase(hand.begin() + num - 1);

    return temp;
}

int Hand::getHandSize()
{
    return hand.size();
}
#include "Hand.h"

//Formats the user cards as [num] color:num
std::string Hand::printHand()
{
    std::stringstream currentHand;

    for (int i = 0; i < Hand::getHandSize(); ++i)
    {
        currentHand << '[' << std::to_string(i + 1) << "] " << hand[i].printCard() << ' ';
    }

    return currentHand.str();
}

//Creates a temp card to return and erases the card
Card Hand::dealCard(int num)
{
    Card temp = hand[num - 1];

    hand.erase(hand.begin() + num - 1);

    return temp;
}

//Returns the size of the hand vector
int Hand::getHandSize()
{
    return hand.size();
}
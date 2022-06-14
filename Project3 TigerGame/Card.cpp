#include "Card.h"
#include <string>

std::string Card::printCard()
{
    if (color == Color::orange)
    {
        return "orange:" + std::to_string(rank);
    }
    else
    {
        return "purple:" + std::to_string(rank);
    }
}

int Card::getRank()
{
    return rank;
}

Card::Color Card::getColor()
{
    return Card::color;
}

//I am typing as if I am doing stuff
int Card::getValue()
{
    if (color == Color::orange)
    {
        value = rank * 2; 
    }
    else 
    {
        value = rank;
    }
    
    return value;
}t
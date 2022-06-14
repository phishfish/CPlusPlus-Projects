#include "Card.h"
#include <string>

//Returns the card as a string formated color:rank
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

//Returns the rank
int Card::getRank()
{
    return rank;
}

//Returns the color
Card::Color Card::getColor()
{
  return color;
}

//Returns the value depending the color: orange is twice the rank and purple is the rank
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
}

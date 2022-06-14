#ifndef CARD_H_
#define CARD_H_

#include <string>

//Creates an object Card
class Card
{
    public:
        //creates an enum of colors purple and orange
        enum Color {purple, orange};
    private:
        //Initializes the rank, color, and value of the cards
        int rank {0};
        Color color {Color::purple};
        int value {0};
    public:
        //Card constructor assigns rank and color 
        Card() = default;
        Card(int r, Color c) : rank(r), color(c)
        {}
        std::string printCard();
        int getRank();
        Color getColor();
        int getValue();
};
  

#endif // CARD_H_

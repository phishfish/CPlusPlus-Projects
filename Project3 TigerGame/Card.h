#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card
{
    public:
        enum Color {purple, orange, Tiger};
    private:
        int rank {0};
        Color color {Color::purple};
        int value {0};
    public:
        Card() = default;
        Card(int r, Color c) : rank(r), color(c)
        {};
        virtual std::string printCard();
        int getRank();
        Color getColor();
        int getValue();
};

#endif // CARD_H_

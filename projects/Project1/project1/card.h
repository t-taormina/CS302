// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
#ifndef CARD_H
#define CARD_H
#include "piece.h"


enum card_suit {hearts, diamonds, clubs, spades};
enum card_value {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

class Card: public Piece
{
    public:
        Card();
        Card(card_value arg_value, card_suit arg_suit);
        ~Card();
        void display() const;
        int point_conversion();
        bool is_position(int arg);
        
 
    protected:
        card_value value;
        card_suit suit;
        int position;
};

#endif


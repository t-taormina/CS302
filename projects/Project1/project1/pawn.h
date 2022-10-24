// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
// almost there

#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

// Contains pawn, card, and dice headers.

class Pawn: public Piece 
{
    public:
        Pawn();
        Pawn(int arg_position);
        ~Pawn();
        void display_position();
        int change_position(int);
        bool is_position(int);
 
    protected:
        int position;
};


// Card suits and values 
enum card_suit {hearts, diamonds, clubs, spades, invalid_suit};
enum card_value {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, invalid_value};

class Card: public Piece
{
    public:
        Card();
        Card(int arg_value, int arg_suit);
        //Card(Card& source);
        ~Card();
        void display() const;
        int copy_card(Card& source);
        int point_conversion();
        int set_position(int arg);
        bool is_position(int arg);
        bool is_valid();
        
 
    protected:
        card_value value;
        card_suit suit;
        int position;
};


class Dice: public Piece 
{
    public:
        Dice();
        ~Dice();
        void display() const;
        int roll();
 
    protected:
        int value;
};

#endif


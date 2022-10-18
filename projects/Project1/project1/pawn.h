// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
#ifndef PAWN_H
#define PAWN_H
#include "piece.h"


class Pawn: public Piece 
{
    public:
        Pawn();
        Pawn(int arg_position);
        ~Pawn();
        void display_position();
        void change_position(int);
        bool is_position(int);
 
    protected:
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


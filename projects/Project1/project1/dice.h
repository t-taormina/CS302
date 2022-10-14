// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
#ifndef DICE_H
#define DICE_H


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


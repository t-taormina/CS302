// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
#ifndef PAWN_H
#define PAWN_H


class Pawn: public Piece 
{
    public:
        Pawn();
        ~Pawn();
        void display_position();
        void change_position(int);
        bool is_position(int);
 
    protected:
        int position;
};

#endif


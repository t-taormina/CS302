// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
#ifndef PIECE_H
#define PIECE_H

class Piece 
{
    public:
        Piece();
        ~Piece();
        Piece(bool ind, bool comm);
        void display() const;
        bool is_individual();
        bool is_community();

    protected:
        bool individual; // marked true if the piece is used only by one player, false otherwise
        bool community; // marked true if the piece is used by both players, false otherwise
        // I don't think this is necessarily useful but it does help to get practice with
        // inheritance. If you have any other suggestions for what this class could be
        // responsible for, please let me know!
};

#endif


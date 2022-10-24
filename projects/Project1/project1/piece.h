// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#ifndef PIECE_H
#define PIECE_H


class Piece 
{
    public:
        Piece();
        ~Piece();
        //Piece(Piece& source);
        Piece(bool ind, bool comm);
        void display() const;
        int copy_piece(Piece& source);
        bool is_individual();
        bool is_community();

    protected:
        bool individual; // marked true if the piece is used only by one player, false otherwise
        bool community; // marked true if the piece is used by both players, false otherwise
        // I don't think this is necessarily useful but it does help to get practice with
        // inheritance. If you have any other suggestions for what this class could be
        // responsible for, please let me know!
};


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


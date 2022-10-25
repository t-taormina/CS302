// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
const int INVALID = 9999;


// Contains headers for Piece, Pawn, Card, and Dice classes. These classes contain the
// logic that represents the pieces used in the game.
//================================================================================

class Piece 
{
    public:
        Piece();
        ~Piece();
        Piece(bool ind, bool comm);
        void display() const;
        // Copies prefilled argument. If argument is null, no copy will occur and the
        // piece will remain unchanged.
        int copy_piece(Piece& source);
        bool is_individual();
        bool is_community();

    protected:
        bool individual;
        bool community; 
};


class Pawn: public Piece 
{
    public:
        Pawn();
        Pawn(int arg_position);
        ~Pawn();
        void display_position();
        void display();
        // Updates the position. Bounds checking is performed in function. Arguments out
        // of bounds will set the position value to "INVALID". Invalid is a constant that
        // represents an invalid piece.
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
        // Cards default to invalid suit and invalid value in default constructor.
        Card();
        // Parameterized Constructor used to build deck.
        Card(int arg_value, int arg_suit);
        ~Card();
        void display() const;
        int copy_card(Card& source);
        int point_conversion();
        int set_position(int arg);
        bool is_position(int arg);
        // Checks card data members for validity.
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
        // Couldn't get three useful functions since the dice has one use in this game.
        int roll();
 
    protected:
        int value;
};

#endif


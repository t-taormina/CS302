// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1
#ifndef PLAYER_H
#define PLAYER_H
#include "person.h"


class Player: public Person 
{
    public:
        Player();
        ~Player();
        Player(const Player& to_copy);
        void display() const;
        void add_points(int points);
        void display_points();
        bool is_winner(int& opponent_points);
        void reset_points();
 
    protected:
        int points;
};

#endif


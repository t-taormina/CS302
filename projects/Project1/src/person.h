// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#ifndef PERSON_H
#define PERSON_H

// Contains both person and player headers. These classes contain the logic that
// represents a player of the game. 
//================================================================================

class Person 
{
    public:
        Person();
        // Copy constructor for dynamically allocated character arrays.
        Person(const Person& to_copy);
        // Assignment operator for dynamically allocated character arrays.
        Person& operator=(const Person& arg);
        ~Person();
        void display() const;
        int edit_first_name(char* edit);
        int edit_last_name(char* edit);
 
    protected:
        char* first_name;
        char* last_name;
        int wins;
        int losses;
};


class Player: public Person 
{
    public:
        Player();
        ~Player();
        // Copy constructor for dynamically allocated character arrays.
        Player(const Player& to_copy);
        // Assignment operator for dynamically allocated character arrays.
        Player& operator=(const Player& arg);
        void display() const;
        // Adds argument to existing points data field. If a negative number is provided,
        // 0 will be added.
        int add_points(int points);
        void display_points();
        bool is_winner(const Player& opponent);
        int add_win();
        int add_loss();
        // Sets points to 0.
        int reset_points();
 
    protected:
        int points;
        char* username;
};

#endif


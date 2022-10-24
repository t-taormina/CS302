// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1 CS302

#ifndef PERSON_H
#define PERSON_H

// Contains both person and player headers.

class Person 
{
    public:
        Person();
        Person(const Person& to_copy);
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
        Player(const Player& to_copy);
        void display() const;
        int add_points(int points);
        void display_points();
        bool is_winner(const Player& opponent);
        int reset_points();
 
    protected:
        int points;
        char* username;
};

#endif


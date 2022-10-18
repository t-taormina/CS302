// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#ifndef PERSON_H
#define PERSON_H
#include <string>
using std::string;

// Contains both person and player headers.

class Person 
{
    public:
        Person();
        Person(char* f_name, char* l_name);
        Person(const Person& to_copy);
        ~Person();
        void display() const;
        void edit_first_name(char* edit);
        void edit_last_name(char* edit);
 
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
        Player(char* usrname);
        ~Player();
        Player(const Player& to_copy);
        void display() const;
        void add_points(int points);
        void display_points();
        bool is_winner(int& opponent_points);
        void reset_points();
 
    protected:
        int points;
        char* username;
};

#endif


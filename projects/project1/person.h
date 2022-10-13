// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include <string>
using std::string;


class Person 
{
    public:
        Person();
        ~Person();
        void display() const;
        int roll();
 
    protected:
        string name;
        string age;
        int wins;
        int losses;
};


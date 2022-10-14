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


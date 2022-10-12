// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

#include <string>
using std::string;


class Name 
{
    public:
        Name();
        ~Name();
        void display() const;
        int roll();
 
    protected:
        string name;
};


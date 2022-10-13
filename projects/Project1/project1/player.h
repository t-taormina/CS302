// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

class Player: public Person 
{
    public:
        Player();
        ~Player();
        void display() const;
        void add_points(int);
        void display_points();
        bool is_winner();
        void reset_points();
 
    protected:
        int points;
};


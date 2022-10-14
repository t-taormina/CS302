// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1


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


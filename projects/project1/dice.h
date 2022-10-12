// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1

enum class dice_value { 1, 2, 3, 4, 5, 6};

class Dice 
{
    public:
        Dice();
        ~Dice();
        void display() const;
        int roll();
 
    protected:
        dice_value value;
};


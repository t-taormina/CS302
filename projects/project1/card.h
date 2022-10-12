// Tyler Taormina 
// taormina@pdx.edu
// October 2022
// Program 1


enum class card_suit {hearts, diamonds, clubs, spades};
enum class card_value {1, 2 , 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace};

class Card 
{
    public:
        Card();
        ~Card();
        void display() const;
        void copy_name(string & copy) const;
        int point_conversion();
 
    protected:
        card_suit suit;
        card_value value;
};
 

# Program 1 Write Up
Tyler Taormina - taormina@pdx.edu
CS302 Fall 2022

### Efficiency Writeup
- The purpose of program 1 was to implement a game using object oriented programming
  methods. This allows for separation of responsibility and roles within the game and when
implemented correctly, it can result in less code and simpler maintenance for future
developers among other benefits. A key part to being successful with programming in this
style is to carefully plan and delegate responsibilities for all the classes that are going
to be implemented. With careful planning in place, I then (as Karla loves to say) "found
the similarities, and pushed them up". This creates hierarchies of objects that when used properly allows
for some very efficient and concise functions to be written. In my program I believe
I have done a careful and successful job of isolating objects and their specific jobs.
There are few instances of classes reaching out to other classes and requesting their
member data but in no cases are we trying to manipulate it. The few instances where I do have "getters" and
"setters" are in the node class where the "get/set" functions are used to access the
"next" pointer which is a private data member. Another instance where I have a setter is
in the "Player" class which uses a setter to keep track of points as they are scored
during the course of the game. The last setters are found in the functions for editing 
user data should a user want to change their name, correct a typo, etc. With the minimal 
amount of getting and setting that I have in my program, I think that this indicates a 
solid separation of roles and responsibilities for my classes. 

- The data structures implemented in my program solely consisted of the required
  structures. They were a circular linked list, an array of linear linked lists, and
a vector from the standard template library. The circular linked list served as my deck of
cards where each node in the list was derived from the "Card" class, and in turn the
"Piece" class. The array of linear linked lists served as the hands for each player. The
array was of length 6 and each head node (card) was the card that was in play. As new
hands were dealt, the cards were added at the head pushing everything else back. The
vector served as a container for the pawns in my game. This data structure is probably the
one that I would not include if I had a choice. The vector containing pawns is not
something that needs to change in size during runtime and therefore an array would have
worked just as well in this situation. The other two data structures worked exceptionally
well in the context of my game though. Recursion was used in all repetitive situations and
pointer arithmetic was used where appropriate which helps with the efficiency of my
program. Something that I would like to change might be the way that I transfer nodes from
my circular linked list to the array of linked lists. In both data structures this is what
my "retrieve" method is used for but instead of just getting a deep copy of the data, it
also removes the node from the corresponding list. With this process, there is a lot of
copying going on and I wonder if there might be a more efficient way to go about this.
Overall I learned a lot from this assignment and if I had to do it again I would spend
more time planning and elaborating on my UML and pre coding planning. A clear vision of
objects and their roles makes for a much cleaner development process. 


### GDB Writeup

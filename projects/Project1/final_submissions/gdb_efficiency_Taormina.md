# Program 1 Write Up
Tyler Taormina - taormina@pdx.edu
CS302 Fall 2022

### Efficiency Writeup
- The purpose of program 1 was to implement a game using object oriented programming
  methods. This allows for seperation of responsiblity and roles within the game and when
implemented correctly, it can result in less code and simpler maintenance for future
developers among other benefits. A key part to being successful with programming in this
style is to carefully plan and delegate responsibilities for all the classes that are going
to be implemented. With careful planning in place, I then (as Karla loves to say) "found
the similiarities, and pushed them up". This creates hierarchies of objects that when used properly allows
for some very efficient and concise functions to be written. In my program I believe
I have done a careful and successful job of isolating objects and their specific jobs.
There are few instances of classes reaching out to other classes and requesting their
member data in order to manipulate it. The few instances where I do have "getters" and
"setters" are in the node class where the "get/set" functions are used to access the
"next" pointer which is a private data member. Another instance where I have a setter is
in the "Player" class which uses a setter to keep track of points as they are scored
during the course of the game.  

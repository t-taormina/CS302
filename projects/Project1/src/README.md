# Program 1
## Dice Soccer
Welcome to Dice Soccer! It is a command line game written in C++ for University. The goal
was to use Object Oriented Programming to efficiently create the game. For the majority of
my compilations I use valgrind when running the executable. I do this because it lets me
know exactly when I introduced the leak. I use a zsh script to compile my code since it is
less typing and I am constantly compiling. It looks like this...

```
#!/usr/bin/zsh
g++ -std=c++17 *.cpp -g -Wall
valgrind ./a.out
```
This is stored in a .sh file in the project directory that can be executed by running the 
command "zsh ./{file name}.sh". From here I add a alias in my .zshrc which is in my home 
directory. This alias lets me run the script with a short command such as "run". However, 
it will only run if you are in the directory that the .sh file is stored in. That is just 
the way I set it up. There are limitless ways you can optimize your work flow with zsh and 
bash. But for grading purposes, compiling with the following will work.
 
```
g++ -std=c++17 *.cpp -g -Wall
```
Feedback is always appreciated!

- Tyler


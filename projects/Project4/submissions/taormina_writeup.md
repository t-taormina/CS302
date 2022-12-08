# Program 4 Write Up
Tyler Taormina - taormina@pdx.edu CS302 Fall 2022

### Efficiency Writeup
This project served multiple purposes. For starters, it was a dive into the
python programming language. Mainly, it consisted of learning how to write a
hierarchy of classes, and then incorporating them into data structures, all
from scratch. The data structures implemented were a Red-Black binary tree
and an array of linear linked lists. I refer to the array of linear linked
lists as a "Table" and the binary tree as a "RBtree". This was the first time
I have written a balanced tree in python and it was a great experience. Things
work very differently in python than they do in c++, at least that is how I
felt. Specifically, recursion took me much more time than I thought it would.
I really missed the mutability that c++ provides! All in all I think I did
a decent job in being efficient. For the array of linear linked lists, my 
insertion was sorted, so at any point in time the individual linked lists are
in a sorted state. I chose to a linked list for each Event type. This required
an array of length 3 where index zero was the Home event linked list, index 1
was the Away Event linked list, and index 2 was the Vacation Event linked list.
I could have potentially written a hash table in which we would have immediate
access but since the data structure is intended to support an application that
benefits from sorting, I opted not to do a hash table. I think the main use of
this application will be in seeing what event is next in terms of date/time and
then once that event has concluded, allowing the user to remove it from the 
schedule and store any thoughts that they had on the event. With this use case
in mind, I think my table does a great job. For the red-black tree, the whole
purpose of spending the time to write the functions that "fix" the tree after
insertion and deletion is to be efficient. So, naturally I think my tree is
efficient. Using recursion in this data structure is where I struggled the 
most. It is very different than c++. I now really appreciate the ability to 
manually manage the memory. This being my first red-black tree, I have no idea
how I did. From the test cases that I ran it seemed to be working. However, I 
wouldn't be suprised if someone found a way to break it. Please let me know
your thoughts on places that I could improve. Specifically, anything with 
recursion in python would be great!

### IDE Writeup
For this project I used an IDE sometimes. Not as much as I probably could have. 
I really like vim. Writing code in other editors feels very slow when I don't
have the key bindings that vim provides. To further make the problem worse, I type
on a Colemak keyboard layout. So, my vim is slightly reconfigured compared to 
the standard. Some IDE's offer Colemak vim bindings but not all of them. VS
code is one that does but they are slightly different than what I prefer. It 
works for the most part but I do still avoid it when I can. The main reason I
found myself wanting an IDE for this program was for the debugger.
Specifically, for bugs in my recursive functions. I was setting things to None
all over the place, calling methods on None objects, etc. It was fun. Using
the debuggers helped me to find the exact lines of code where I was making my 
mistakes and in the end this saved me a lot of time. Other than the debugger, I 
will stay away from IDE's. Syntax highlighting is cool, but theres ways to 
get the same thing in vim. Well, happy holidays!




# Program 2 Write Up
Tyler Taormina - taormina@pdx.edu
CS302 Fall 2022

### Efficiency Writeup
 The purpose of this program was to implement a data structure and a object hierarchy in order
to provide a user information about various winter activities in the local area. The
activities that I decided to include in my hierarchy are skiing, snowshoeing, and ice
skating. The data structure is a doubly linked list using templates. This allows one
implementation of the linked list to be used with all three data types thus greatly
reducing the amount of code needed to make this project possible. While the templates do
reduce the amount of code, it does so at something of a cost for someone that has never
used templates, such as myself. Development time was rather slow during this program.
I found myself struggling with syntax for basic functionality that I was familiar with.
Over time, this would naturally get better but for the first time it was quite
challenging. If I were to reattempt this project I think I would attempt to get assistance
sooner rather than later as wrong syntax seemed to plague me for the first few days of
coding. Aside from the nature of templates, I found this project to be a good exercise in
design. Determining a useful and efficient hierarchy resulted in clear and separate roles
for each object in the hierarchy. I believe I did a better job of separating the
differences and pushing up the common with this program than I did in the first one. The
few getters and setters that I do have are in the doubly linked list and node classes. As
this program isn't necessarily needing to take input to fulfill requirements, I was able
to pre establish all objects needed to provide the client program enough functionality for
testing. Given more time I would absolutely like to have this be something that the user
would interact with and add to. It could serve as a combination of a journal and brochure.
A brochure in which the user can learn about the common places to do common activities.
A journal in which they can rate their experience of an activity at a given location,
leave a written review of the activity, and even add activities that they discover. To be
clear, this is the vision of the project and not the current state. Some things that
I like about this program are the use of the STL containers for ratings. They provide
a quick solution for dynamic storage of simple integer data. It would be overkill to write
a full on class for this data given its minimal usage in the program. Something that
I might change about this program would be the use of a doubly linked list. I say this
only with consideration for the program's current state. There are few algorithm
requirements in this project and I don't think anything that I wrote truly takes advantage
of having two pointers in a node. I believe that the code could be simplified with
a simple linear linked list. Granted, as functionality gets added over time to the program
and data structure, then there would likely be more suitable use cases for a doubly linked
list. Overall, I think this project was a good exercise in getting familiar with
templates, operator overloading, and exception handling.

### GDB Writeup
 As with my previous project, I made extensive use of valgrind in testing my program at
each compilation. I make this a habit because it makes memory leak detection so much
easier if you have a specific block of code that you can correlate with your memory loss.
If you program away and forget to test for leaks, I find that it just adds more work later
on finding those segments of code in which you are leaking bytes. GDB on the other hand
did not get used quite as much with this program. I tried to use it during my recursive
functions even if they were working in order to keep practicing the process. However, the
algorithms were fairly straight forward in this project and didn't prove to be so
difficult as to need trouble shooting with GDB. What I did make extensive use of in this
program was the compiler errors. This is something everyone does (or should do) with every
program, but with the amount of syntax errors that I encountered during working with
templates for the first time... The compiler errors were all I had to reference. Reading
the errors at times can be daunting but I found that with practice this became much
easier. A lot of the errors that I was making was not being consistent with ``` const ```
keywords in my hierarchy. This would throw mismatched type errors. At first they were hard
to make sense of, but after fixing the first few they were familiar enough and easy to
spot and correct. Overall, I would say that I became much more comfortable with the
debugging tools GDB and Valgrind. In addition, I would say that my relationship with the
gnu compiler is improving as well! 
 

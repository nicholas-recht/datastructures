###############################################################
# Program:
#     Lesson 06, LIST
#     Brother Helfrich, CS235
# Author:
#     Nicholas Recht
#     Justin Ricks
# Summary:
#     Contains a file for the implementation of a linked list
#     class that operates similar to the stl list. Also contains
#     a class called WholeNumber that is used to represent arbitrary
#     length integers. Included is a driver program to test both
#     of these classes and a program used to generate fibonacci
#     numbers.
#     Extra: select option 5 on the lesson06 driver to test
#     out the various extra credit functions of the WholeNumber
#     class. Constant iterators were also created and used. 
# Time:
#     12 hrs combined
###############################################################

##############################################################
# The main rule
##############################################################
a.out: list.h lesson06.o fibonacci.o wholeNumber.o wholenumberdriver.o
	g++ -o a.out lesson06.o fibonacci.o wholeNumber.o wholenumberdriver.o
	tar -cf lesson06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson06.o     : the driver program
#      fibonacci.o    : the logic for the fibonacci-generating function
#      <anything else?>
##############################################################
lesson06.o: list.h lesson06.cpp 
	g++ -c lesson06.cpp

fibonacci.o: fibonacci.h fibonacci.cpp list.h 
	g++ -c fibonacci.cpp 

wholeNumber.o: wholeNumber.h wholeNumber.cpp 
	g++ -c wholeNumber.cpp 

wholenumberdriver.o: wholenumberdriver.cpp wholeNumber.h 
	g++ -c wholenumberdriver.cpp 
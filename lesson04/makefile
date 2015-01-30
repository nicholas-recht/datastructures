###############################################################
# Program:
#     Lesson 04, DEQUE
#     Brother Helfrich, CS235
# Author:
#     Nicholas Recht
#     Justin Ricks
# Summary:
#     Contains the implementation for the deque container and
#     several driver programs to test it. One of the drivers is
#     a nowServing program which simulates the now serving
#     procedure for the Linux Lab.
# Time:
#     5.5 hrs combined
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h lesson04.o nowServing.o
	g++ -o a.out lesson04.o nowServing.o
	tar -cf lesson04.tar *.h *.cpp makefile

dequeDriver: deque.h dequeDriver.cpp
	g++ -o dequeDriver deque.h dequeDriver.cpp

##############################################################
# The individual components
#      lesson04.o     : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
lesson04.o: deque.h lesson04.cpp
	g++ -c lesson04.cpp

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp

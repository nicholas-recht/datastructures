###############################################################
# Program:
#     Lesson 01, SET
#     Brother Helfrich, CS235
# Author:
#     Nicholas Recht
#     Adam Cameron
# Summary:
#     This is the makefile for the set class and the driver
#     program. The driver program contains a simple game
#     of go fish, which reads a set of cards into a hand, which
#     the user must then guess. The lesson01.cpp file contains
#     the different driver programs for the set class. The set.h
#     file contains the implementation for the set class and the
#     goFish.cpp and goFish.h files contain the implementation
#     for the go fish card game. 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: set.h lesson01.o goFish.o card.o
	g++ -o a.out lesson01.o goFish.o card.o
	tar -cf lesson01.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson01.o     : the driver program
#      goFish.o       : the logic for the goFish game
#      card.o         : a single playing card
##############################################################
lesson01.o: set.h goFish.h lesson01.cpp
	g++ -c lesson01.cpp

goFish.o: set.h goFish.h goFish.cpp card.h
	g++ -c goFish.cpp

card.o: card.h card.cpp
	g++ -c card.cpp 
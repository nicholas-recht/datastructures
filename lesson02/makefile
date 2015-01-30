###############################################################
# Program:
#     Lesson 02, STACK
#     Brother Helfrich, CS235
# Author:
#     Nicholas Recht
#     Adam Cameron
# Summary:
#     This program creates and implements the Stack abstract
#     data type. It contains a simple driver program that firstly
#     tests the stack implementation, and then uses it to convert
#     entered infix equations to postfix equations and postfix equations
#     to machine assembly instructions. 
# Time:
#     7 hrs combined + 1 extra credit
###############################################################

##############################################################
# The main rule
##############################################################
a.out: stack.h lesson02.o infix.o infixconversion.o assemblyconversion.o
	g++ -o a.out lesson02.o infix.o infixconversion.o assemblyconversion.o
	tar -cf lesson02.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson02.o     : the driver program
#      infix.o        : the logic for the infix --> postfix program
##############################################################
lesson02.o: stack.h infix.h lesson02.cpp
	g++ -c lesson02.cpp

infix.o: stack.h infix.h infix.cpp infixconversion.h assemblyconversion.h
	g++ -c infix.cpp

infixconversion.o: infixconversion.h infixconversion.cpp
	g++ -c infixconversion.cpp

assemblyconversion.o: assemblyconversion.h assemblyconversion.cpp
	g++ -c assemblyconversion.cpp


###############################################################
# Program:
#     Lesson 08, Binary Search Tree
#     Brother Helfrich, CS265
# Author:
#     Justin Ricks
#     Nicholas Recht
# Summary:
#     This file contains an implementation of a binary search
#     tree and a driver program to test it. The BST is used
#     to implement a binary sort.
# 
# Time:
#     7 hrs combined
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lesson08.o
	g++ -o a.out lesson08.o
	tar -cf lesson08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson08.o     : the driver program
##############################################################
lesson08.o: bst.h lesson08.cpp sortBinary.h
	g++ -c lesson08.cpp


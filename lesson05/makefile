###############################################################
# Program:
#     Lesson 05, NODE
#     Brother Helfrich, CS235
# Authors:
#     Nick Recht, Justin Ricks
# Summary:
#     This program implements the insertion sort using nodes in
#     a linked list. node.h contains a template class for
#     representing nodes in a doubly-linked list.
#     sortInsertion.h contains the implementation of the
#     insertion sort algorithm using nodes.
#
# Time:
#     Approx 4 hrs combined. Speed demons!
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h lesson05.o 
	g++ -o a.out lesson05.o 
	tar -cf lesson05.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson05.o      : the driver program
##############################################################
lesson05.o: node.h lesson05.cpp sortInsertion.h
	g++ -c lesson05.cpp

###############################################################
# Program:
#     Lesson 09, Map
#     Brother Helfrich, CS265
# Author:
#     Justin Ricks, Nicholas Recht
# Summary:
#     This precious .tar contains little packets of beauty. Not
#     only does it contain an implementation of the red-black
#     tree, but also a Map container, and a program that counts
#     the frequency of words in a file. What more could you want?
#     :D
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lesson09.o wordCount.o
	g++ -o a.out lesson09.o wordCount.o 
	tar -cf lesson09.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson09.o     : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
lesson09.o: bst.h pair.h map.h lesson09.cpp
	g++ -c lesson09.cpp

wordCount.o: map.h wordCount.cpp bst.h
	g++ -c wordCount.cpp 

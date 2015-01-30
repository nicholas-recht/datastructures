###############################################################
# Program:
#     Lesson 07, Binary Tree
#     Brother Helfrich, CS265
# Author:
#     Justin Ricks
#     Nicholas Recht
# Summary:
#     This file contains a BinaryNode class and a driver program
#     to test it. It also contains a program which generates
#     huffman codes from a file.
# Time:
#     7 Hrs combined
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lesson07.o huffman.o 
	g++ -o a.out lesson07.o huffman.o 
	tar -cf lesson07.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson07.o     : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
lesson07.o: bnode.h huffman.h lesson07.cpp
	g++ -c lesson07.cpp

huffman.o: bnode.h huffman.h huffman.cpp
	g++ -c huffman.cpp


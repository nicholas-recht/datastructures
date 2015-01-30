###############################################################
# Program:
#     Lesson 12, Graph
#     Brother Helfrich, CS265
# Author:
#     <your name here>
# Summary:
#     <put a description here>
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lesson12.o graph.o maze.o
	g++ -o a.out lesson12.o graph.o maze.o
	tar -cf lesson12.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson12.o     : the driver program
##############################################################
lesson12.o: graph.h vertex.h lesson12.cpp
	g++ -c lesson12.cpp 

graph.o: graph.h set.h vertex.h graph.cpp
	g++ -c graph.cpp

maze.o: maze.cpp maze.h vertex.h graph.h
	g++ -c maze.cpp

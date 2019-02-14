#-----------------------------------------------------------------------------
# Name: Sidharth Naik ID: 1647945 Class: 12B/M Date: January 29,2018
# Description: Compiles the cfiles File Name: Makefile
# -----------------------------------------------------------------------------

PROGRAM_NAME = charType
FLAGS        = -std=c99 -Wall
SOURCES      = $(PROGRAM_NAME).c
OBJECTS      = $(PROGRAM_NAME).o
EXEBIN       = $(PROGRAM_NAME)

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm $(EXEBIN) $(OBJECTS)

submit :
	submit  cmps012b-pt.w19 lab4 charType.c README Makefile

check :
	valgrind --leak-check=full charType charType.c outfile

submitCheck :
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.w19/lab4/sidnaik

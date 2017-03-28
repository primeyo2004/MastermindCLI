##
##  Makefile 
##  Mastermind
##
##  Created by Jeune Prime Origines on 27/3/17.
##  Copyright © 2017 Jeune Prime Origines. All rights reserved.
##


CC=g++
CFLAGS=-c -Wall -std=c++11 -I./ -I./Mastermind/
LDFLAGS=
SOURCES=./Application.cpp \
	./BasicFactory.cpp \
	./BasicParams.cpp \
	./BasicValidation.cpp \
	./CmdLineUI.cpp \
	./CodePegRandomGen.cpp \
	./Game.cpp \
	./main.cpp \
	./Mastermind/MastermindCore.cpp \
	./Mastermind/MastermindFactory.cpp \
	./Mastermind/MastermindLogic.cpp \
	 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=mmgame

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f *.o ./Mastermind/*.o mmgame 

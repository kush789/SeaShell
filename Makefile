#==============================================================================
#
#					This file is part of SeaShell.
#
#	SeaShell is free software; you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation; either version 2 of the License, or
#	(at your option) any later version.
#
#==============================================================================
#******************************************************************************
#
#	Copyright (C) 2015 Kushagra Singh | kushagra14056 @ iiitd.ac.in
#
#******************************************************************************

CC = gcc
CFLAGS = -c -Wall
SOURCES = src/begin.c src/execute_command.c src/get_command.c src/seashell.c \
		  src/understand_command.c
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = SeaShell

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
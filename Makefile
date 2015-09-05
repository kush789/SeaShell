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

CC=g++
CFLAGS=-c -Wall
SOURCES=
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=seashell

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o

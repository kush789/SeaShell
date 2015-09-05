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
CFLAGS = -c -g -Wall

SOURCES = src/seashell.c src/execute_command.c
OBJECTS = $(SOURCES:.c=.o)

HEADER = seashell.h
LIB = libSeaShell.a

TEMP_HEADER_PATH = ./include/$(HEADER)
HEADER_INCLUDE_PATH = /usr/local/include/

TEMP_LIB_PATH = ./$(LIB)
LIB_INSTALL_PATH = /usr/local/lib/

all: $(SOURCES) $(LIB)
    
$(LIB): $(OBJECTS) 
	ar -rcs $(LIB) $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

install: $(LIB)
	cp $(TEMP_HEADER_PATH) $(HEADER_INCLUDE_PATH)
	cp $(TEMP_LIB_PATH) $(LIB_INSTALL_PATH)
	rm $(TEMP_LIB_PATH)
	rm $(OBJECTS)

clean:
	rm $(HEADER_INCLUDE_PATH)$(HEADER)
	rm $(LIB_INSTALL_PATH)$(LIB)

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

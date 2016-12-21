CC = g++
CFLAGS = -Wall -Wextra -Wconversion -g

all: spellcheck

clean:
	rm -f spellcheck *.o *~

spellcheck: spellcheck.o hashtable.o linkedlist.o util.o
	$(CC)  -o spellcheck spellcheck.o hashtable.o linkedlist.o util.o

spellcheck.o: spellcheck.cpp hashtable.hpp util.hpp
	$(CC) $(CFLAGS) -o spellcheck.o -c spellcheck.cpp

hashtable.o: hashtable.cpp hashtable.hpp linkedlist.hpp util.hpp
	$(CC) $(CFLAGS) -o hashtable.o -c hashtable.cpp

linkedlist.o: linkedlist.cpp linkedlist.hpp
	$(CC) $(CFLAGS) -o linkedlist.o -c linkedlist.cpp

util.o: util.cpp util.hpp
	$(CC) $(CFLAGS) -o util.o -c util.cpp


CC := g++
WARN := -Wall -Wextra -Wconversion

# -DNDEBUG disables assert
#CCOPTS := $(WARN) -O -DNDEBUG

# assert is enabled
CCOPTS := $(WARN) -O

tic-tac-toe: tic-tac-toe.o gameboard.o
	$(CC) tic-tac-toe.o gameboard.o -o tic-tac-toe

tic-tac-toe.o: tic-tac-toe.c gameboard.h
	$(CC) $(CCOPTS) tic-tac-toe.c -o tic-tac-toe.o -c

gameboard.o: gameboard.c gameboard.h
	$(CC) $(CCOPTS) gameboard.c -o gameboard.o -c

clean:
	rm -rf *.o *~ tic-tac-toe


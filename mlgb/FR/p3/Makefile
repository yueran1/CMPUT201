CC:=g++
CCOPTS:= -Wall -Wextra -Wconversion -o


p3: p3.o points.o
	g++ -o p3 p3.o points.o
%.o : %.c
	$(CC) $(CCOPTS)$@ -c $<
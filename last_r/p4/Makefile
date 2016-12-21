CC:=g++
CCOPTS:= -Wall -Wextra -Wconversion -o


p4: p4.o points.o
	g++ -o p4 p4.o points.o
%.o : %.c
	$(CC) $(CCOPTS)$@ -c $<

clean:
	rm -rf *.o p4
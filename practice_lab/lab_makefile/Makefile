foobar: foobar.o foo.o bar.o
	g++ -o foobar foobar.o foo.o bar.o
foobar.o: foobar.c foo.h bar.h
	g++ -o foobar.o foobar.c -c
foo.o: foo.c foo.h bar.h
	g++ -o foo.o foo.c -c
bar.o: bar.c bar.h
	g++ -o bar.o bar.c -c
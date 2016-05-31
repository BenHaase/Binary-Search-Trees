bjh3B:bjh3B.o
	g++ -o bjh3B bjh3B.o
bjh3B.o:bjh3B.cpp
	g++ -c bjh3B.cpp
clean:
	/bin/rm -f bjh3B bjh3B.o

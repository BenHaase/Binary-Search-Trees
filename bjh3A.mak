bjh3A:bjh3A.o
	g++ -o bjh3A bjh3A.o
bjh3A.o:bjh3A.cpp
	g++ -c bjh3A.cpp
clean:
	/bin/rm -f bjh3A bjh3A.o

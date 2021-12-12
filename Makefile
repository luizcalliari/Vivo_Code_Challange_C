main:
	g++ -c movie.cpp -o movie.o
	g++ -c main.cpp -o main.o
	g++ -o main main.o movie.o -lcurl

test:
	g++ -c movie.cpp -o movie.o
	g++ -c unit_test.cpp -o unit_test.o
	g++ -o unit_test unit_test.o movie.o -lcurl

clean:
	rm -f main main.o movie.o unit_test unit_test.o 

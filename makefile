run: 
	g++ $(n).cpp -O2 -std=c++2a
	./a.out

compare:
	g++ $(n).cpp -std=c++2a
	./a.out < in > myout
	diff myout out

view:
	g++ $(n).cpp -std=c++2a
	./a.out < in > myout

test:
	g++ $(n).cpp -std=c++2a
	./a.out < in > myout
	g++ test.cpp -std=c++2a
	./a.out
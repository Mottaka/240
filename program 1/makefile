GPP = g++ -O3 -Wall -std=c++11

PRG = Aprog

Aprog: main.o
	   $(GPP) -o $(PRG) main.o
main.o: main.cc
	   $(GPP) -o main.o -c main.cc

clean:
	rm $(PRG)
	rm main.o

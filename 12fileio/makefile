GPP = g++ -O3 -Wall -std=c++11


intro: intro.h intro.cc
	$(GPP) -o intro intro.cc

eof: eof.h eof.cc
	$(GPP) -o eof eof.cc

read_frac: read_frac.h read_frac.cc fraction.o
	$(GPP) -o read_frac read_frac.cc fraction.o

fraction.o: fraction.h fraction.cc
	$(GPP) -o fraction.o -c fraction.cc

int_list.o: int_list.h int_list.cc
	$(GPP) -o int_list.o -c int_list.cc

clean:
	rm -f intro 
	rm -f eof
	rm -f read_frac
	rm -f fraction.o 
	rm -f test_int_list 
	rm -f int_list.o 

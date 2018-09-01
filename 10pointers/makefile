GPP = g++ -O3 -Wall -std=c++11


arrays: arrays.h arrays.cc fraction.o
	$(GPP) -o arrays arrays.cc fraction.o

test_int_list: test_int_list.h test_int_list.cc int_list.o
	$(GPP) -o test_int_list test_int_list.cc int_list.o

fraction.o: fraction.h fraction.cc
	$(GPP) -o fraction.o -c fraction.cc

int_list.o: int_list.h int_list.cc
	$(GPP) -o int_list.o -c int_list.cc

clean:
	rm -f arrays 
	rm -f test_int_list 
	rm -f fraction.o 
	rm -f int_list.o 

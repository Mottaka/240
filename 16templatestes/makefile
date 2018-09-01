GPP = g++ -g -O3 -Wall -std=c++11

test_dyn_array: test_dyn_array.o
	$(GPP) -o test_dyn_array test_dyn_array.o

test_dyn_array.o: test_dyn_array.cc test_dyn_array.h dyn_array.cc dyn_array.h
	$(GPP) -o test_dyn_array.o -c test_dyn_array.cc

test_vector: test_vector.cc test_vector.h
	$(GPP) -o test_vector test_vector.cc

test_iterator: test_iterator.cc test_iterator.h
	$(GPP) -o test_iterator test_iterator.cc

clean:
	rm -f test_dyn_array
	rm -f test_dyn_array.o
	rm -f test_vector
	rm -f test_iterator


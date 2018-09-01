GPP = g++ -g -O3 -Wall -std=c++11

all: test_vector2d test_point2d test_polygon
	@echo Making All Test Files

test_polygon: point2d.o polygon.o test_polygon.o vector2d.o
	$(GPP) -o test_polygon point2d.o polygon.o test_polygon.o vector2d.o; \
	./test_polygon;

test_vector2d: test_vector2d.o vector2d.o
	$(GPP) -o test_vector2d test_vector2d.o vector2d.o; \
	./test_vector2d;

test_point2d: test_point2d.o
	$(GPP) -o test_point2d test_point2d.o point2d.o vector2d.o; \
	./test_point2d;

test_vector2d.o: test_vector2d.cc test_vector2d.h vector2d.o
	$(GPP) -o test_vector2d.o -c test_vector2d.cc

test_point2d.o: test_point2d.cc test_point2d.h point2d.o vector2d.o
	$(GPP) -o test_point2d.o -c test_point2d.cc

test_polygon.o: test_polygon.cc
	$(GPP) -o test_polygon.o -c test_polygon.cc

vector2d.o: vector2d.cc vector2d.h
	$(GPP) -o vector2d.o -c vector2d.cc

point2d.o: point2d.cc point2d.h vector2d.o
	$(GPP) -o point2d.o -c point2d.cc

polygon.o: polygon.cc polygon.h
	$(GPP) -o polygon.o -c polygon.cc

clean:
	rm -f polygon.o
	rm -f point2d.o 
	rm -f vector2d.o 
	rm -f test_polygon
	rm -f test_polygon.o
	rm -f test_vector2d 
	rm -f test_vector2d.o
	rm -f test_point2d 
	rm -f test_point2d.o 


#ifndef _240_LECT_16TEMPLATES_TEST_VECTOR_H_
#define _240_LECT_16TEMPLATES_TEST_VECTOR_H_

#include <iostream>
using std::endl;
using std::cin;
using std::cout;
#include <vector>
using std::vector;

int main(int argc, char** argv);

void TestPrintVectorAt(const vector<int>& v);
void TestPrintVectorIt(vector<int>& v);
void TestPrintVectorConstIt(const vector<int>& v);

void TestScaleVectorAt(const vector<int>& v);
void TestScaleVectorIt(vector<int>& v);
void TestScaleVectorConstIt(const vector<int>& v);

#endif

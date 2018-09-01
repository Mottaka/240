/* 
 * Author: Ian Osea
 * for csce240 summer 2017
 * hw4
 * */

#ifndef VERTEXNODE_H
#define VERTEXNODE_H

#include "point2d.h"

//using namespace std;
using csce240::Point2d;
namespace csce240{
struct VertexNode  {
  
  Point2d vertex_;
  VertexNode* next_;
  VertexNode* prev_;
  VertexNode(Point2d& vertex, 
  VertexNode* next,
  VertexNode* prev);
};

int main(int, char**);

}
#endif

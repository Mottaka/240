/**
 * Author: Ian Osea
 * CSCE240 SUMMER 2017
 * HW5
 * 
 * */

#include "vertexnode.h"


VertexNode :: VertexNode(Point2d& vertex, VertexNode* next, VertexNode* prev)  {
  vertex_ = vertex;
  next_ = next;
  prev_ = prev;
}

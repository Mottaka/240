/* 
 * Author: Ian Osea 
 * For: CSCE240 Summer 2017
 *
 * */

#include "vertexnode.h"
//using csce240::Point2d;
using csce240::VertexNode;

VertexNode::VertexNode(Point2d& vertex, VertexNode* next, VertexNode* prev)  {
  vertex_ = vertex;
  next_ = next;
  prev_ = prev;
}


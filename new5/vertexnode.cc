#include "vertexnode.h"


VertexNode :: VertexNode(Point2d& vertex, VertexNode* next, VertexNode* prev)  {
  vertex_ = vertex;
  next_ = next;
  prev_ = prev;
}

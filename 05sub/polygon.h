/**
 * Author: Ian Osea
 * CSCE240 SUMMER 2017
 * HW5
 * 
 * */

#ifndef _240_HW_05_POLYGON_H
#define _240_HW_05_POLYGON_H

#include <string>
using std::to_string;
#include <assert.h>
#include "vertexnode.h"

//using namespace std;

namespace csce240  {
  
    class Polygon  {

  private:

  int size_;
  VertexNode* vertices_;

  public:

  static unsigned char k_init_success_, 
                       k_init_not_polygon_, 
                       k_init_nonunique_, 
                       k_init_has_collinear_;

  Polygon();
  Polygon(Polygon& original);
  ~Polygon();

  int Init(Point2d* vertices, int count);
  void Offset(Vector2d by);
  void Scale(double by, Point2d about);
  int size();

  string ToString();
  Polygon& operator=(Polygon& original);

  void Add(Point2d& vertex);
  void ClearVertices();
	};
}
#endif 

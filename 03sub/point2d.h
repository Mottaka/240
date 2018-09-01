
/**
Ian Osea
Homework 3
CSCE 240 Summer 2017
Point-Vector calculator
**/

#ifndef _240_HW_03_SUBS_POINT2D_H
#define _240_HW_03_SUBS_POINT2D_H
#include "vector2d.h"

class Point2d
{
private:

  double x_;
  double y_;

public:

  Point2d();
  Point2d(double x, double y);

  double x();
  double y();

  Vector2d Subtract(Point2d& rhs);
  Point2d Add(Vector2d& rhs);

  bool EqualTo(Point2d& rhs);
  bool NotEqualTo(Point2d& rhs);

  double DistanceToSquared(Point2d& to);
  double DistanceTo(Point2d& to);

  string ToString();
  Vector2d operator-(Point2d& rhs);
  Point2d operator+(Vector2d& rhs);

  bool operator==(Point2d& rhs);
  bool operator!=(Point2d& rhs);
};

#endif

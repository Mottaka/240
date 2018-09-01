/**
Ian Osea
Homework 3
CSCE 240 Summer 2017
Point-Vector calculator
**/

#include "point2d.h"
#include <string>
#include <math.h>

//x_ and y_ init
Point2d::Point2d()  {
  x_ = 0.0;
  y_ = 0.0;
}

Point2d::Point2d(double x, double y)  {
  x_ = x;
  y_ = y;
}

double Point2d::x()  {
  return x_;
}

double Point2d::y()  {
  return y_;
}
//subtraction
Vector2d Point2d::Subtract(Point2d& rhs)  {
  Vector2d *vec = new Vector2d();
  vec->setx(this->x_ - rhs.x_);
  vec->sety(this->y_ - rhs.y_);
  return *vec;
}
//addition
Point2d Point2d::Add(Vector2d& rhs)  {
  Point2d *p = new Point2d();
  p->x_ = this->x_ + rhs.x();
  p->y_ = this->y_ + rhs.y();
  return *p;
}
//equality check
bool Point2d::EqualTo(Point2d& rhs)  {
  if (this->x_ == rhs.x() && this->y_ == rhs.y())
    return true;
    else
    return false;
}
//inequality check
bool Point2d::NotEqualTo(Point2d& rhs)  {
  if (this->x_ == rhs.x() && this->y_ == rhs.y())
    return false;
    else	
    return true;
}
//distance check
double Point2d::DistanceToSquared(Point2d& to)  {
  double dx = this->x_ - to.x();
  double dy = this->y_ - to.y();
  return dx*dx + dy*dy;
}
//sim to previous but root
double Point2d::DistanceTo(Point2d& to)  {
  double dx = this->x_ - to.x();
  double dy = this->y_ - to.y();
  return sqrt(dx*dx + dy*dy);
}

string Point2d::ToString()  {
  string str = "(";
  str = str + to_string(this->x());
  str += ", ";
  str = str + to_string(this->y());
  str = str + ")";
  return str;
}
//overload -op
Vector2d Point2d::operator-(Point2d& rhs)  {
  return this->Subtract(rhs);
}
//overload +op
Point2d Point2d::operator+(Vector2d& rhs)  {
  return this->Add(rhs);
}
//overload equalto
bool Point2d::operator==(Point2d& rhs)  {
  return this->EqualTo(rhs);
}
//overload notequalto
bool Point2d::operator!=(Point2d& rhs)  {
  return this->NotEqualTo(rhs);
}

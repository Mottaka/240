/**
Ian Osea
Homework 3
CSCE 240 Summer 2017
Point-Vector calculator
**/

#include "vector2d.h"
#include <math.h>
#include <string>
//x_ and y_ init
Vector2d::Vector2d()  {
  x_ = 0.0;
  y_ = 0.0;
}

Vector2d::Vector2d(double x,double y)  {
  x_ = x;
  y_ = y;
}

double Vector2d::x()  {
  return x_;
}

double Vector2d::y()  {
  return y_;
}

void Vector2d::setx(double x)  {
  x_ = x;
}

void Vector2d::sety(double y)  {
  y_ = y;
}
//vector addition
Vector2d Vector2d::Add(Vector2d& rhs)  {
  Vector2d *vec = new Vector2d();
  vec->x_ = this->x_ + rhs.x_;
  vec->y_ = this->y_ + rhs.y_;
  return *vec;
}
//vector subtraction
Vector2d Vector2d::Subtract(Vector2d& rhs)  {
  Vector2d *vec = new Vector2d();
  vec->x_ = this->x_ - rhs.x_;
  vec->y_ = this->y_ - rhs.y_;
  return *vec;
}
//reversal
Vector2d Vector2d::Reverse()  {
  Vector2d *vec = new Vector2d();
  vec->x_ = (-1)*this->x_; 
  vec->y_ = (-1)*this->y_;
  return *vec;
}
//vector scale
Vector2d Vector2d::Scale(double scalar)  {
  Vector2d *vec = new Vector2d();
  vec->x_ = this->x_ * scalar;
  vec->y_ = this->y_ * scalar;
  return *vec;
}
//vector equality
bool Vector2d::EqualTo(Vector2d& rhs)  {
  if (this->x_ == rhs.x_ && this->y_ == rhs.y_)
    return true;
    else
    return false;
}
//vector inequality
bool Vector2d::NotEqualTo(Vector2d& rhs)  {
  if (this->x_ == rhs.x_ && this->y_ == rhs.y_)
    return false;
    else
    return true;
}
//vector length 
double Vector2d::GetLength()  {
  return sqrt(x_*x_ + y_*y_);
}
//vector unit
Vector2d Vector2d::GetUnit()  {
  double magnitude = sqrt(x_*x_ + y_*y_);
  magnitude = 1 / magnitude;
  Vector2d *vec = new Vector2d();
  vec->x_ = this->x_*magnitude;
  vec->y_ = this->y_*magnitude;
  return *vec;
}
//vector to_string
string Vector2d::ToString()  {
  string str = "(";
  str = str + to_string(x_);
  str = str + ", ";
  str = str + to_string(y_);
  str = str + ")";
  return str;
}
//vector op+ overload
Vector2d Vector2d::operator + (Vector2d& rhs)  {
  return this->Add(rhs);
}
//vector op- overload
Vector2d Vector2d::operator - (Vector2d& rhs)  {
  return this->Subtract(rhs);
}
//equalto overload
bool Vector2d::operator==(Vector2d& rhs)  {
  return this->EqualTo(rhs);
}
//notequalto overload
bool Vector2d::operator!=(Vector2d& rhs)  {
  return this->NotEqualTo(rhs);
}
//reversal overload
Vector2d Vector2d::operator-()  {
  return this->Reverse();
}
//scalar overload
Vector2d Vector2d::operator* (double scalar)  {
  return this->Scale(scalar);
}

//Vector2d& Vector2d::operator *= (double scalar) {
  //return this->Scale(scalar);
//}

/**
 * Author: Ian Osea
 * vector2d.h fle for hw4
 * csce240 summer 2017
 *
 **/

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include<string>
using std::string;
using std::to_string;

#include<iostream>
using std::ostream;

namespace csce240  {
  
  class Vector2d  {
	
  private:
    double x_;
    double y_;

  public:
    Vector2d();
    Vector2d(double x, double y);
    double x();
    double y();
    void setx(double x);
    void sety(double y);
    Vector2d Add(Vector2d& rhs);
    Vector2d Subtract(Vector2d& rhs);
    Vector2d Reverse();
    Vector2d Scale(double scalar);
    bool EqualTo(Vector2d& rhs);
    bool NotEqualTo(Vector2d& rhs);
    double GetLength();
    Vector2d GetUnit();
    string ToString();

    Vector2d operator+(Vector2d& rhs);
    Vector2d operator-(Vector2d& rhs);
    bool operator==(Vector2d& rhs);
    bool operator!=(Vector2d& rhs);
    Vector2d operator-();
    //Vector2d operator*(const Vector2d& rhs, double scalar);
    Vector2d& operator*= (double scalar);
    Vector2d operator* (double scalar);
    friend ostream& operator <<(ostream& out, Vector2d& vector);

    };
    inline Vector2d operator* (double f, Vector2d m) {
    return m.Scale(f);
	
    }

}

#endif


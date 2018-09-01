#ifndef POINT2D_H
#define POINT2D_H
#include<iostream>
#include"vector2d.h"
namespace csce240
{
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
		static bool Collinear(Point2d& a, Point2d& b, Point2d& c);
		friend ostream& operator << (ostream& out, Point2d& point);
	};
}
#endif // !POINT2D_H
#pragma once

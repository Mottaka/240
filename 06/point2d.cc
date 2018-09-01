#include"point2d.h"
#include<string>
#include<math.h>

using csce240::Point2d;
using csce240::Vector2d;

Point2d::Point2d()
{
	x_ = 0.0;
	y_ = 0.0;
}
Point2d::Point2d(double x, double y)
{
	x_ = x;
	y_ = y;
}
double Point2d::x()
{
	return x_;
}
double Point2d::y()
{
	return y_;
}
Vector2d Point2d::Subtract(Point2d& rhs)
{
	Vector2d *vec = new Vector2d();
	vec->setx(this->x_ - rhs.x_);
	vec->sety(this->y_ - rhs.y_);
	return *vec;
}
Point2d Point2d::Add(Vector2d& rhs)
{
	Point2d *p = new Point2d();
	p->x_ = this->x_ + rhs.x();
	p->y_ = this->y_ + rhs.y();
	return *p;
}
bool Point2d::EqualTo(Point2d& rhs)
{
	if (this->x_ == rhs.x() && this->y_ == rhs.y())
		return true;
	else
		return false;
}
bool Point2d::NotEqualTo(Point2d& rhs)
{
	if (this->x_ == rhs.x() && this->y_ == rhs.y())
		return false;
	else
		return true;
}
double Point2d::DistanceToSquared(Point2d& to)
{
	double dx = this->x_ - to.x();
	double dy = this->y_ - to.y();
	return dx*dx + dy*dy;
}
double Point2d::DistanceTo(Point2d& to)
{
	double dx = this->x_ - to.x();
	double dy = this->y_ - to.y();
	return sqrt(dx*dx + dy*dy);
}
string Point2d::ToString()
{
    
	string str = "(";
	str = str + to_string(this->x());
	str += ", ";
	str = str + to_string(this->y());
	str = str + ")";
	return str;
}

Vector2d Point2d::operator-(Point2d& rhs)
{
	return this->Subtract(rhs);
}

Point2d Point2d::operator+(Vector2d& rhs)
{
	return this->Add(rhs);
}

bool Point2d::operator==(Point2d& rhs)
{
	return this->EqualTo(rhs);
}
bool Point2d::operator!=(Point2d& rhs)
{
	return this->NotEqualTo(rhs);
}

bool Point2d::Collinear(Point2d&a, Point2d& b, Point2d& c)
{
	double Ax = a.x_;
	double Ay = a.y_;
	double Bx = b.x_;
	double By = b.y_;
	double Cx = c.x_;
	double Cy = c.y_;
	if (((Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By)) / 2) == 0)
	{
		return true;
	}
	return false;
}

ostream & csce240::operator<<(ostream & out, Point2d & point)
{
	out << "(" << point.x() << ", " << point.y() << ")";
	return out;
}
